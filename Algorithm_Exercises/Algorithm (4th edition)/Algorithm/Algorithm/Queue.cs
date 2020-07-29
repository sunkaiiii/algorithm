﻿using System;
using System.Collections.Generic;
using System.Text;

namespace Chapter1
{
    public class Queue<T>
    {
        private Node<T> first;
        private Node<T> last;
        private int N { get; set; }
        public bool IsEmpty { get { return N == 0; } }
        public int Size { get { return N; } }

        public Queue() { }
        public Queue(Queue<T> oldQeue)
        {
            T[] nodes = new T[oldQeue.Size];
            int index = 0;
            while(!oldQeue.IsEmpty)
            {
                var current = oldQeue.Dequeue();
                nodes[index++] = current;
            }
            foreach(var node in nodes)
            {
                oldQeue.Enqueue(node);
                Enqueue(node);
            }
        }
        
        public void Enqueue(T item)
        {
            Node<T> oldlast = last;
            last = new Node<T>();
            last.Item = item;
            last.Next = null;
            if (IsEmpty)
                first = last;
            else
                oldlast.Next = last;
            N++;
        }

        public T Dequeue()
        {
            T item = first.Item;
            first = first.Next;
            if (IsEmpty)
                last = null;
            N--;
            return item;
        }

        public void Reverse()
        {
            var first = this.first;
            last = this.first;
            Node<T> reverse = null;
            while (first != null)
            {
                var second = first.Next;
                first.Next = reverse;
                reverse = first;
                first = second;
            }
            this.first = reverse;
        }
    }
}
