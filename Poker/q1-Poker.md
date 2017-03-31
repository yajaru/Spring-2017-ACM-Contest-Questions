# Poker Night At The Major's Lab

>COME ONE, COME ALL TO POKER NIGHT AT THE MAJOR'S LAB!
THE RULES ARE LOOSE, THE TABLES ARE DIRTY AND EVERYWHERE IS THE SMELL OF DREAMS!

Tonight we have two gloriously named contestants: Player One and Player Two!
They will go head to head in a winner takes all contest of gruel and grit
to determine who is the most beloved by lady fortune!

We had constructed a supreme judging tool to determine the winner but, fortune struck us and stole it in a freak wolf attack!

We need you, dear contestant, to recreate our judge! To ensure the the rules are followed! To keep the auditors happy!

### Input

Our dealers will supply you with the players hands, five cards each, like follows:
- 8A 9S 6C QH 4A 2C 4S 3H AS TH

The values of the cards in order are 2 3 4 5 6 7 8 9 T J Q K A<br>
The suits are S H C D<br>

We will tell you how many rounds to expect

### Output

For each round, we need to know which player has won
- Say PLAYER 1 if Player One wins
- Say PLAYER 2 if Player Two wins
- Say TIE if neither wins

The hands from most winning to least
- Straight Flush
    - A full set of consecutive cards, all of the same suit
- Four of a Kind
    - A set of four cards of the same value
- Full House
    - Three cards of a value and two of another
- Two Pairs
    - A set of two different pairs
- Highest Card
    - Who ever has the highest card
    - If the highest cards tie, take the next highest
    - And so on

If both hands are of the same type, use the highest card rule.
If that doesn't work, there is a tie.

<span style="font-size:0.75em">These are not real poker rules. They are better. Use only these rules.</span>

### Sample Input/Output
|Sample Input|Sample Output|
|---|---|
|4 ||
|2H 3H 4H 5H 6H 3C 3S 3D 2C 2D |PLAYER 1|
|3C 3S 3D 2C 2D 2H 3H 4H 5H 6H|PLAYER 2|
|TH JH QH KH AH TC JC QC KC AC|TIE|
|2C 4H 6D 8S AS 3H 4S 6C 8C AH|PLAYER 2|
