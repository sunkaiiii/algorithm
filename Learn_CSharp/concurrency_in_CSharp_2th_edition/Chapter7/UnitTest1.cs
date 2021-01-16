
using Microsoft.Reactive.Testing;
using Microsoft.VisualStudio.TestTools.UnitTesting;
using System;
using System.Net.Http;
using System.Reactive.Linq;
using System.Threading.Tasks;
using System.Threading.Tasks.Dataflow;

namespace Chapter7
{
    [TestClass]
    public class UnitTest1
    {
        [TestMethod]
        public async Task TestMethod1()
        {
            var testedClass = new TestedClass();
            int result = await testedClass.GetResultAsyn();
            Assert.AreEqual(result, 1);
        }

        // ��Ԥ��ʧ�ܵ�async�������е�Ԫ����
        [TestMethod]
        public async Task TestMethod2()
        {
            var testedClass = new TestedClass();
            await Assert.ThrowsExceptionAsync<DivideByZeroException>(async () =>
            {
                await testedClass.ThrowExceptionAsync();
            });
        }

        // ��������������е�Ԫ����
        [TestMethod]
        public async Task BlockTest()
        {
            var block = new TransformBlock<int, int>(item =>
            {
                if (item == 1)
                    throw new InvalidOperationException("Blech.");
                return item * 2;
            });
            block.Post(2);
            block.Post(4);
            block.Complete();

            Assert.AreEqual(4, block.Receive());
            Assert.AreEqual(8, block.Receive());
            await block.Completion;
        }

        // ��System.Reactive�ɹ۲������е�Ԫ����
        [TestMethod]
        public async Task TestSystemReactive()
        {
            var my = new TestedClass();
            var result = await my.GetString("www.google.com").SingleAsync();
            Assert.AreEqual("stub", result);

            await Assert.ThrowsExceptionAsync<HttpRequestException>(async () =>
            {
                await my.GetString("Exception").SingleAsync();
            });
        }

        // ͨ��α����ȶ�System.Reactive�ɹ۲������е�Ԫ����
        [TestMethod]
        public void TestSystemReactiveWithDelay()
        {
            var scheduler = new TestScheduler();
            var my = new TestedClass();
            string result = null;
            my.GetStringWithTimeout("www.google.com",scheduler).Subscribe(r => result = r);
            scheduler.Start();
            Assert.AreEqual("stub", result);
        }
    }
}
