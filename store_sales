import generalfunc

print('''
Store Sales

1: Print the sales
2: Sort Low to High
3: Sort High to Low
4: Highest and Lowest
5: Total Sales
6: Average Sales
7: Enter Figures
8: Save Sales to File
9: Open Sales from File

''')

salesarr=[]
sales_store_file = "store_sales.txt"

def save_sales():
    output_file = open(sales_store_file, 'w')

    for sale in salesarr:
        output_file.write(str(sale) + "\n")

    output_file.close()

def open_sales():
    salesarr.clear()
    
    input_file = open(sales_store_file, 'r')
    count = 0
    
    for line in input_file:
        salesarr.append(int(line)          )
        count = count + 1
        print("Sales for store ", count, " are ", line.strip())

    input_file.close()

def print_sales():
    print("Sales Figures Below: \n")
    count = 1
    for item in salesarr:
        print("Sales for Store ", count, ": ", item)
        count = count + 1
            

def sort_low_high():
    for sort_pass in range(0, len(salesarr)-1):
        for count in range(0 ,len(salesarr)-1):
                if salesarr[count]>salesarr[count+1]:
                    temp=salesarr[count]
                    salesarr[count] = salesarr[count+1]
                    salesarr[count+1] = temp
                         
    print_sales()

def sort_hi_low():
    for sort_pass in range(0, len(salesarr)-1):
        for count in range(0 ,len(salesarr)-1):
                if salesarr[count]<salesarr[count+1]:
                    temp=salesarr[count]
                    salesarr[count] = salesarr[count+1]
                    salesarr[count+1] = temp
                         
    print_sales()

def highest_lowest():
    highest_sale = salesarr[0]
    highest_stand = 1
    lowest_stand = 1
    lowest_sale = salesarr[0]
    
    for indsale in range(0, len(salesarr)):
        if highest_sale < salesarr[indsale]:
            highest_sale = salesarr[indsale]
            highest_stand = indsale + 1

        if lowest_sale > salesarr[indsale]:
            lowest_sale = salesarr[indsale]
            lowest_stand = indsale + 1
        
    print("Highest Sale was by stand ", highest_stand, " with ", highest_sale)
    print("Lowest Sale was by stand ", lowest_stand, " with ", lowest_sale)
    

def total_sales():
    totalsales = 0
    
    for indvsale in range(0, len(salesarr)):
        totalsales = totalsales + salesarr[indvsale]

    return totalsales

def average_sales():
    print(total_sales()/len(salesarr))
    
def register_sales(itemcount = 5):
    salesarr.clear()
    
    for item in range(1, itemcount+1):
        storesale = generalfunc.checkInput("Enter sales for stand #" + str(item) + ": ")
        salesarr.append(storesale)


register_sales(7)

while True:
    menu_item = generalfunc.checkInput("Enter your command: ", 1, 9, "Not a valid option")

    if menu_item == 1:
        print_sales()
    elif menu_item == 2:
        sort_low_high()
    elif menu_item == 3:
        sort_hi_low()
    elif menu_item == 4:
        highest_lowest()
    elif menu_item == 5:
        print(total_sales())
    elif menu_item == 6:
        average_sales()
    elif menu_item == 7:
        register_sales()
    elif menu_item == 8:
        save_sales()
    elif menu_item == 9:
        open_sales()

    print("")

