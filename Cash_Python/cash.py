change = 0
coins25 = 0
coins10 = 0
coins5 = 0
coins1 = 0

# Get change input from user and promt until it qualifies
while(change <= 0):
    change = float(input("Enter your change here: "))
    cents = change * 100

    while(cents >= 25):
        cents -= 25
        coins25 += 1

    while(cents >= 10):
        cents -= 10
        coins10 += 1

    while(cents >= 5):
        cents -= 5
        coins5 += 1

    while(cents >= 1):
        cents -= 1
        coins1 += 1
    
print(f"You will need at list {coins25} coins of 25.")
print(f"You will need at list {coins10} coins of 10.")
print(f"You will need at list {coins5} coins of 5.")
print(f"You will need at list {coins1} coins of 1.")