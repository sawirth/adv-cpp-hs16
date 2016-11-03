package ch.advcpp;

public interface Matcher<E> {
    /**
     * Returns true if the given element matches the definition
     * @param elem The element to check for a match
     * @return true on match else false
     */
    boolean match(E elem);
}
