package Summarize.LOL;

public class weapon {
    private String code;//武器的代号

    public weapon() {
    }

    public weapon(String code) {
        this.code = code;
    }

    public String getCode() {
        return code;
    }

    public void setCode(String code) {
        this.code = code;
    }

    @Override
    public String toString() {
        return code;
    }
}
