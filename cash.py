#import get float from cs50 lib
from cs50 import get_float

#while true, input float, mutiply that by 100 and round
while True:
    cash_owed = get_float('Change Owed: $ ')
    change = round(cash_owed * 100);
    # if negitive number prompt user again
    if change >= 0:
        break

coins = 0
# set of each coin value
coin_amount = [25, 10, 5, 1]

#for eachvalue of coin, while change is great or = to the value of i (coint value) 
#sub tract the first value of coin amount, thats 1 coin, subtract the second amount, thats 2 coints and so on. 

for i in coin_amount:
    while change >= i:
        change -= i
        coins += 1
print(coins)

