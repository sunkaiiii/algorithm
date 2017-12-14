package chapter8命令者模式;

/**
 * Created by sunkai on 2017/12/12
 */
public class Save implements Action {
    private final Editor editor;

    public Save(Editor editor){
        this.editor=editor;
    }

    @Override
    public void perform() {
        editor.save();
    }
}
