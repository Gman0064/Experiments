using System;
using System.Collections.Generic;

class WhatDoesTheFoxSay
{
    static void Main()
    {
        int cases = Int32.Parse(Console.ReadLine());

        while(cases > 0) {
            var sounds = new List<string>();
            sounds.AddRange(Console.ReadLine().Split(' '));

            bool otherAnimals = true;
            while(otherAnimals) {
                string animalIn = Console.ReadLine();
                if (animalIn.IndexOf("?") > -1) {
                    otherAnimals = false;
                    string foxSays = "";
                    for(int i=0; i < sounds.Count; i++) {
                        foxSays = String.Concat(foxSays, sounds[i]);
                        if (i < (sounds.Count - 1)) {
                            foxSays = String.Concat(foxSays, " ");
                        }
                    }
                    Console.WriteLine(foxSays);
                    cases -= 1;
                } else {
                    string[] sentence;
                    sentence = animalIn.Split(' ');
                    sounds.RemoveAll(item => item == sentence[sentence.Length - 1]);
                }
            }
        }
    }
}