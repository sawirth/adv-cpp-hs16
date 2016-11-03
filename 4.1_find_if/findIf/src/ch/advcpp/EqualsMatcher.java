package ch.advcpp;

public class EqualsMatcher<E> implements Matcher<E> {

    private E matchObject;

    public EqualsMatcher(E matchObject) {
        this.matchObject = matchObject;
    }

    @Override
    public boolean match(E elem) {
        return elem.equals(matchObject);
    }
}
