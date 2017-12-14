package chapter8.策略模式;

import java.io.IOException;
import java.io.OutputStream;

/**
 * Created by sunkai on 2017/12/14
 */
public interface CompressionStrategy {
    public OutputStream compress(OutputStream data) throws IOException;
}
