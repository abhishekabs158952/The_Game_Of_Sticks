# The_Game_Of_Sticks

variables
1.)t : no of testcase
2.)caseNo : case type
3.)n : no of sticks
4.)turn : which player has tha turn
5.)winner : winner of the game

main : 
1.)if caseNo=1
	1.i)n=14
	1.ii)n=21
	1.iii)n=53
2.)if caseNo=2
	game between human and program
3.)if caseNo=3
	both the player is program
4.)in each case:
	4.i)game
  		4.i.a)fastgame(if n>30)
		4.i.b)chooseBest
5.)Decide winner (who dont pick last stick)

Discription of funtion :
4.i)game : 
	choose to fast calulate best way (if n>20),
	otherwise explore the and or tree with alpha beta pruning
	4.i.a)fastgame :
		if((n-k)%4==1) and k belongs to {1,2,3} then pick k sticks else pick 1 stick
	4.i.b)chooseBest :
		 explore the and or tree with alpha beta pruning
 
