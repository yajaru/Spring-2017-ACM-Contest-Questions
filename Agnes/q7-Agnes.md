# I Got It From Preston

Oh no! Plague has entered the FSU CS department. One of our beloved graduate comrades has betrayed us and brought the enemy upon us. We are ignorant of the transgressor but, have faith! There is a way to trace the spread of this disease. Using the power of Facebook, our access to student schedules and a legal grey area darker than the Heart of Bob Meyers, the Dark Lord of All Objects, Destroyer of Grades, praise be, we have found the viability that the disease spread between any two humans(but not animals, funnily enough).

We need you, loyal comrade, to find the the most viable path of spread, so that we might *re-educate* the transgressors.

## Input

We beseech you, aid us in our task; we give you the names of the sick and the viability of transmission as the following form:

First shall come the number of the afflicted.
- There shall be more than 4
- There shall be less than infinity
Second shall be the names of the afflicted.
- Shame them, for they are tainted.
Finally shall come a listing of the of the infection probabilities.
- There shall be 2 listings for each pair of people
- In each listing
    - first shall come the name of the infector
    - second shall come the name of the infected
    - third shall come the viability of that infection as a number > 0 and < 1
        - higher numbers shall be more viable

Only one transgressor has brought this disease, of this we are sure. Woe to them who has poisoned us comrades! But worry not, those infected may not be infected again.

## Output

Return to us with a listing of the transmissions for the most viable spread.
- The viability of the whole spread is the multiplication of the of the transmissions.

For each listing
- First comes the name of the infector
- Second comes the name of the infected

Order this list, my comrade, by the names of pairs in alphabetical order.

## Sample Input/Output
|Sample Input|Sample Output|
|---|---|
|4||
|Sharanya Andrew Jarrod Preston|Andrew Jarrod|
|Sharanya Andrew 0.05454|Jarrod Sharanya|
|Sharanya Jarrod 0.78397|Preston Andrew|
|Sharanya Preston 0.33949||
|Andrew Sharanya 0.42219||
|Andrew Jarrod 0.69626||
|Andrew Preston 0.020391||
|Jarrod Sharanya 0.86928||
|Jarrod Andrew 0.63811||
|Jarrod Preston 0.03724||
|Preston Sharanya 0.02373||
|Preston Andrew 0.83516||
|Preston Jarrod 0.63918||
