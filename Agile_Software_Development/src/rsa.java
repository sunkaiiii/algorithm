import com.sun.xml.internal.messaging.saaj.util.ByteInputStream;

import java.io.BufferedReader;
import java.io.ByteArrayInputStream;
import java.io.InputStream;
import java.io.InputStreamReader;
import java.security.KeyPairGenerator;
import java.security.interfaces.RSAPrivateKey;
import java.security.interfaces.RSAPublicKey;
import java.util.Base64;
import java.util.HashMap;

/**
 * Created by sunkai on 2017/12/8
 */
public class rsa {
    public static void main(String args[]){
        // TODO Auto-generated method stub
        try {
            KeyPairGenerator keyPairGenerator = KeyPairGenerator.getInstance("RSA");
            keyPairGenerator.initialize(1024);
            keyPairGenerator.generateKeyPair();
            System.out.println(keyPairGenerator.generateKeyPair().getPublic());
        }
        catch (Exception e){}
//        byte[] a={0x15,0xa0,0x00,0xa3,0x3b,0xeb,0x91,0xeb,0x82,0x2b,0xfe,0x98,0xf3,0xba,0x5f,
//                0x06,0x05,0xe0,0x63,0x47,0x4f,0xb7,0x70,0xc3,0x02,0x68,0x65,0x3a,0xed,0xd3,0x9f,
//                0x03,0xf0,0xe5,0x8d,0x56,0xc9,0xf1,0x01,0x70,0x21,0x1f,0xef,0x35,0x06,0x58,0x13,
//                0x3d,0xc5,0x75,0x60,0xf7,0x65,0x22,0x05,0x8d,0x7d,0x3e,0x6a,0xdd,0x4e,0xc9,0x0a,
//                0x6e,0xa9,0x1b,0xcb,0x8e,0x15,0xce,0xbf,0x87,0x67,0x5e,0x69,0x72,0x89,0x1a,0x11,
//                0xc0,0x06,0x12,0xbc,0x77,0x9b,0xfd,0x08,0x3e,0x63,0xaf,0x96,0xcb,0x16,0xa8,0x65,
//                0x26,0xa7,0xfb,0xe2,0xe0,0x1c,0x6e,0xd7,0x50,0x13,0x74,0x2d,0x94,0x13,0x17,0x7a,
//                0xae,0x25,0xfb,0xcb,0xb1,0x26,0xf8,0x88,0x94,0x80,0xd6,0xfb,0xff,0xaf,0xb1,0x78,
//                0xf1,0xc5,0x3a,0x41,0x36,0x40,0x05,0xd6,0xcc,0x31,0x87,0x6c,0x5c,0xad,0xa5,0x21,
//                0x42,0xdd,0x9c,0xa3,0xbc,0x70,0xb6,0x61,0x05,0xab,0xf7,0x3a,0x96,0xc4,0x37,0x56,
//                0xa8,0xfd,0x60,0x60,0x99,0xa6,0x31};
        InputStreamReader in=new InputStreamReader(new ByteArrayInputStream(a));
        BufferedReader reader=new BufferedReader(in);
        String c=null;
        try{
            c=reader.readLine();
        }catch (Exception e){};

        System.out.println(Base64.getEncoder().encode());
    }
}