package com.example.sunkai.zhihuscrollad;

import android.content.Context;
import android.graphics.Bitmap;
import android.graphics.Canvas;
import android.graphics.RectF;
import android.graphics.drawable.BitmapDrawable;
import android.graphics.drawable.Drawable;
import android.support.annotation.Nullable;
import android.support.v7.widget.AppCompatImageView;
import android.util.AttributeSet;

/**
 * Created by sunkai on 2017/12/8.
 */

public class AdImageView extends AppCompatImageView {

    public AdImageView(Context context, @Nullable AttributeSet attrs) {
        super(context, attrs);
    }

    private int mDx;

    private int mMinDx;

    @Override
    protected void onSizeChanged(int w, int h, int oldw, int oldh) {
        super.onSizeChanged(w, h, oldw, oldh);

        mMinDx=h;
    }

    public void setDx(int dx){
        if(getDrawable()==null)
            return;

        mDx=dx-mMinDx;
        if(mDx<=0)
            mDx=0;
        if(mDx>getDrawable().getBounds().height()-mMinDx)
            mDx=getDrawable().getBounds().height()-mMinDx;
        invalidate();
    }

    public int getDx(){
        return mDx;
    }

    @Override
    protected void onDraw(Canvas canvas) {
        Drawable drawable=getDrawable();
        int w=getWidth();
        int h=(int)(getWidth()*1.0f/drawable.getIntrinsicWidth()*drawable.getIntrinsicHeight());
        drawable.setBounds(0,0,w,h);
        canvas.save();
        canvas.translate(0,-getDx());
        super.onDraw(canvas);
        canvas.restore();
    }
}

