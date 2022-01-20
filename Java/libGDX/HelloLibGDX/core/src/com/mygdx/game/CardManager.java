package com.mygdx.game;
import java.util.ArrayList;

public class CardManager {

    private int numDecks = 5;
    private int cardsInSuit = 13;

    public ArrayList<String> deck = new ArrayList<String>();
    //private PlayerHand playerHand;

    public void BuildDeck()
    {
        String[] suits = new String[] {"c", "d", "h", "s"};

        for (int i = 0; i < numDecks; i++)
        {
            for (int j = 0; j < suits.length; j++)
            {
                for (int k = 1; k <= cardsInSuit; k++)
                {
                    String cardValue = i + suits[j] + k;
                    deck.add(cardValue);
                    System.out.println(cardValue);
                }
            }
        }
    }
}
