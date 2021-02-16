import random
k,g,w=["rock","paper","sissors"],0,0 # key,gameCount,winCount
while True:
    if (p:=input("\nRock paper or sissors? ").lower()) not in k:continue # p is palayer
    print(p.capitalize(),"vs",(c:=random.choice(k)).capitalize()) # c is computer
    print(("You %s!"%("Lose","Win")[c==k[k.index(p)-1]],"Tie.")[p==c],"\nGames Played:",g:=g+1,"\nWin Ratio: %"+str((w:=w+(c==k[k.index(p)-1]))/g*100))
    if input("Keep Playing? (y/n): ").lower()!="y":break