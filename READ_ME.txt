Project Details:
This project contains a login.txt file, which includes 3 user login details:
user1
paswd1

user2
paswd2

user3
paswd3

If you wish, you may sign up which will create an extra login.
The program uses a linked list.
The program itself runs an number of options.
1) Allows you to add a new player to the linked list.
2)Displays all current players in the list.
3)Allows you to search for a player using his IRFU Number, if found, will display
that players details.
4) Will allow you to search for a player, again using the IRFU Number, and
update that players details.
5) Will allow you to search a player using his IRFU Number, and delete
that player from the list.
6) Will give you stats on a specific subject; position or weight. If position
is selected, it will ask you for which position and will return stats on
that position for all players in that position.
If weight is selected, you will be prompted for a weight (kg - float), and 
all players over that weight will be included in the stats.
All stats are printed to an output file called 'report.txt'.
7)Repeats option 6, along with outputting all players to an output file called
'Rugby.txt'.
8)**Not complete**
-1)This will end the program, and will output 2 files, one being 'Rugby.txt' - 
for the user. The other being 'readIn.txt' for the program. The readIn.txt file
is used for reading in previous players into the program, so after each session,
the players will be saved.

--Points to note--
All methods used uses validation, the program is not prone to crashing.
The password being entered is hidden from the user.
You can also 'sign up', along with just being able to log in.
All players are saved, unless deleted by the user.
The entire program is done by using a linked list.

--Missing from program--
Option 8.
Search name aswel as IRFU Number for searching player.
Sort players in order when adding them.