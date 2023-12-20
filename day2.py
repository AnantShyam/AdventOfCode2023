red, green, blue = 12, 13, 14

with open("input.txt", "r") as f:
    file = f.readlines()
    
    result = 0
    for id, line in enumerate(file):
        game = []
        round = []
        word = ""
        
        for character in line:
            if character not in [" ", ",", ";", ":"]:
                word = word + character
            else:
                if character in [" ", ",", ":"]:
                    if word != "":
                        round.append(word)
                    word = ""
                else:
                    round.append(word)
                    word = ""
                    game.append(round[2:])
                    round = []
        
        isvalid = True 
        for round in game:
            for i in range(0, len(round), 2):
                num, color = int(round[i]), round[i + 1]
                if color == "red" and num > red:
                    isvalid = False 
                elif color == "green" and num > green:
                    isvalid = False 
                elif color == "blue" and num > blue:
                    isvalid = False 
        
        if isvalid:
            result += id

    print(result)
        
                
        


