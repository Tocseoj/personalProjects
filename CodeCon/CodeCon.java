//Problem        : How fast can news go
//Language       : Java
//Compiled Using : javac
//Version        : Java 1.7.0_75
//Input for your program will be provided from STDIN
//Print out all output from your program to STDOUT

/**
 * CS180 - CodeCon: How fast can news go
 * Find the rate at which news travels
 * @author Joseph Marshall, marsha87@purdue.edu, 804
 */

import java.lang.String;import java.lang.System;import java.util.Scanner;

//Your submission should *ONLY* use the following class name
public class CodeCon
{
    public static void main(String[] args) {
        Scanner stdin = new Scanner(System.in);
        int n = 5;
        int k = 2;
        int t = 1;

        stdin.close();

        int[] peopleKnow = new int[n];
        for (int i = 0; i < n; i++) {
            if (i == 0) {
                peopleKnow[i] = k;
            } else {
                peopleKnow[i] = 0;
            }
        }

        int time = 0;
        int finalTime = 0;
        boolean finalTimeSet = false;

        if (k != 1) {
            while (peopleKnow[n - 1] < k) {
                for (int i = 0; i < n; i++) {
                    if (peopleKnow[i] > 0) {
                        peopleKnow[i] -= 1;
                        boolean runLoop = true;
                        boolean bool = false;
                        for (int j = 0; j < n; j++) {
                            if (runLoop) {
                                if (bool == false && peopleKnow[j] > 0) {
                                    bool = true;
                                }
                                if (bool == true && peopleKnow[j] == 0) {
                                    peopleKnow[j] = k;
                                    runLoop = false;
                                }
                            }
                           if (!finalTimeSet && peopleKnow[n-1] == k) {
                               finalTime = time;
                               finalTimeSet = true;
                               break;
                           }
                        }
                    }
                    time++;
                    if (finalTimeSet) {
                        break;
                    }
                }
            }
            if (finalTime != 0) {
                System.out.println(t * finalTime);
            }
            else {
                System.out.println(t * time);
            }

        }
        else {
            System.out.println(t * (n - 1));
        }
    }
}

