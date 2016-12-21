package com.example.mashizhao.myapplication;

/**
 * Created by MaShiZhao on 2016/12/20.
 */
public class JniUtil
{
    static {
        System.loadLibrary("jniutil");
    }

    public native String jniUtilTest();
}
