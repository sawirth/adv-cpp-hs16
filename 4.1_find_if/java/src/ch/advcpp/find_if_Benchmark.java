package ch.advcpp;

import java.util.ArrayList;
import java.util.Iterator;
import java.util.List;
import java.util.concurrent.ThreadLocalRandom;

public class find_if_Benchmark<E>
{
    private List<Integer> numberOfIterations = new ArrayList<>();
    private List<Long> numberOfElapsedTimes = new ArrayList<>();
    private static final int NUMBER_OF_RUNS = 10000;
    private static final int RANGE = 1000000;

    private Iterator<E> find_if(Iterator<E> iter, Matcher<E> matcher)
    {
        int counter = 1;
        while(iter.hasNext())
        {
            if(matcher.match(iter.next()))
            {
                break;
            }

            counter++;
        }

        numberOfIterations.add(counter);
        return iter;
    }

    public void run()
    {
        //Create list with millions of random numbers between 0 and RANGE
        int size = RANGE;
        ArrayList<Integer> list = new ArrayList<>(size);
        for (int i = 0; i < size; i++)
        {
            list.add(ThreadLocalRandom.current().nextInt(0, RANGE));
        }

        for (int i = 0; i < NUMBER_OF_RUNS; i++)
        {
            int numberToFound = ThreadLocalRandom.current().nextInt(0, RANGE);
            Matcher<Integer> matcher = new EqualsMatcher<>(numberToFound);
            long start = System.nanoTime();
            Iterator<E> iter = find_if((Iterator<E>)list.iterator(), (Matcher<E>)matcher);
            long elapsedTime = (System.nanoTime() - start);
            numberOfElapsedTimes.add(elapsedTime);
        }

        //Calculate averages
        double avgElapsedTime = 0;
        double avgIterations = 0;
        if (numberOfElapsedTimes.size() != numberOfIterations.size())
        {
            System.out.println("Something went wrong..");
            return;
        }

        for (int i = 0; i < numberOfElapsedTimes.size(); i++)
        {
            avgElapsedTime += numberOfElapsedTimes.get(i);
            avgIterations += numberOfIterations.get(i);
        }

        avgElapsedTime = avgElapsedTime / numberOfElapsedTimes.size();
        avgIterations = avgIterations / numberOfIterations.size();

        System.out.println("Average time in nanoseconds: " + avgElapsedTime);
        System.out.println("Average iterations: " +  avgIterations);
    }
}
