/*
 * @Author: your name
 * @Date: 2020-02-29 21:45:17
 * @LastEditTime: 2020-03-03 21:06:29
 * @LastEditors: Please set LastEditors
 * @Description: In User Settings Edit
 * @FilePath: /exam/Main.java
 */

import java.util.ArrayList;
import java.util.Random;

public class Main {

    private static int weightSum = 0;
    private static int valueSum = 0;
    private final static int WEIGHT = 50;

    public static void main(String[] args) {
        Thing[] thing = new Thing[6];

        for (int i = 0; i < thing.length; i++) {
            thing[i] = new Thing(new Random().nextInt(50), new Random().nextInt(100));
        }

        // 输出随机产生的物品重量、价值属性
        for (int i = 0; i < thing.length; i++) {
            System.out.println("物品" + i + "(weight=" + thing[i].getWeight() + ",value=" + thing[i].getValue() + ") ");
        }

        int maxIndex = 0;
        maxIndex = getSum(thing);
        ArrayList<ArrayList<Thing>> S = null;
        S = getSub(thing);
        ArrayList<Thing> max_subSet = S.get(maxIndex);
        System.out.print("最优组合为：");
        for (int i = 0; i < max_subSet.size(); i++) {
            System.out.print("(" + max_subSet.get(i).getWeight() + "," + max_subSet.get(i).getValue() + ") ");
        }
    }

    // 使用二进制法，找出所有物品组合的子集
    static ArrayList<ArrayList<Thing>> getSub(Thing thing[]) {
        ArrayList<ArrayList<Thing>> S = new ArrayList<ArrayList<Thing>>();
        ArrayList<Thing> subSet = null;

        int max = 1 << thing.length;

        for (int i = 0; i < max; i++) {
            subSet = new ArrayList<Thing>();

            int k = i;
            // 0、1分别表示物品“不存在”，“存在”存在子集里
            int index = 0;
            while (k > 0) {
                if ((k & 1) > 0) {
                    subSet.add(thing[index]);
                }
                k >>= 1;
                index++;
            }
            S.add(subSet);
        }
        return S;
    }

    // 计算每个子集中物品的价值总量，并找出最大价值量的子集
    static int getSum(Thing[] thing) {
        ArrayList<ArrayList<Thing>> S = null;
        S = getSub(thing);
        int[] weightSum = new int[S.size()];
        int[] valueSum = new int[S.size()];
        int maxValue = valueSum[0];
        int maxIndex = 0;
        for (int i = 0; i < S.size(); i++) {
            ArrayList<Thing> subSet = S.get(i);

            for (int j = 0; j < subSet.size(); j++) {

                /*
                 * weightSum[i]+=thing[j].getWeight(); valueSum[i]+=thing[j].getValue();
                 */
                weightSum[i] += subSet.get(j).getWeight();
                valueSum[i] += subSet.get(j).getValue();
            }
            if (weightSum[i] <= WEIGHT) {
                if (valueSum[i] >= maxValue) {
                    maxValue = valueSum[i];
                    maxIndex = i;
                }
            }
        }
        return maxIndex;
    }

}

class Thing {

    private int weight;
    private int value;

    Thing(int weight, int value) {
        this.weight = weight;
        this.value = value;
    }

    public void setWeight(int weight) {
        this.weight = weight;
    }

    public int getWeight() {
        return weight;
    }

    public void setValue(int value) {
        this.value = value;
    }

    public int getValue() {
        return value;
    }
}
