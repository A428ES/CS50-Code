def checkForRepeat():
        mainString = input("String to search: ")
        specChar = input("What to look for: ")
        charsInString = len(mainString)
        searchLen = len(specChar)
        strLoc = 0
        confIns = 0

        for indChar in mainString:
                whileLoop = 0
                compString = ""
                while whileLoop < searchLen:
                        calcNum = strLoc + whileLoop
                        try:
                                compString = compString + mainString[calcNum]
                        except:
                                detectedError = 1
                        finally:
                                whileLoop += 1

                if compString == specChar:
                        confIns+=1

                strLoc+=1


        print(confIns)
        checkForRepeat()

checkForRepeat()
