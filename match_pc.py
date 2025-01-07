import csv

def compute_range(start_address,end_address):
    range_list = []
# Ensure start_address is less than end_address
    if start_address > end_address:
        start_address, end_address = end_address, start_address
    # Iterate through the range and print each address
    for address in range(start_address, end_address + 1):
        range_list.append(hex(address))
    return range_list
    range_list.clear()
    
def read_csv_file(file_name):
    dictionary = {}
    with open(file_name, 'r', newline='') as csvfile:
        reader = csv.reader(csvfile, delimiter=",")
        for row in reader:
            dictionary[row[0]] = compute_range(int(row[1],16),int(row[2],16))
    return dictionary


def write_to_file(file_name, data):
    f = open(file_name, 'a')
    f.write(data)




def check_pc(second_file_name,file_name):
    data = []
    dictionary = {}
    counter = 0
    dic = read_csv_file(file_name)
    strace = []
    program_found = False
    i=-1
    with open(second_file_name, 'r') as file:
        for line in file:
            counter = counter + 1
            parts = line.strip().split(" ")
            if parts[0] == "PROGRAM":
                print(counter,parts[2])
                for x in dic:
                #if program_found:
                    if (parts[2] in dic[x]):
                        
                        if(x in strace):
                            key_index = strace.index(x)
                            num_to_pop = len(strace) - key_index - 1 
                            for _ in range(num_to_pop):
                                strace.pop()
                        else:

                            strace.append(x)
                        break      
                                          
            elif parts[0] == "Load" or "Store":
                write_to_file("5stacktrace.txt","->".join(strace) + " " + line)
         
    
                    

def drone_reg(file_name):
    dictionary = {}
    with open(file_name, 'r', newline='') as csvfile:
        reader = csv.reader(csvfile, delimiter=",")
        for row in reader:
            dictionary[row[1]] = row[0]
    return dictionary
   
   
                  
def drone_result(second_file_name,file_name):
    dic = {}
    dic = drone_reg(file_name)
    counter = 0
    with open(second_file_name, 'r') as file:
        for line in file:
            counter = counter + 1
            parts = line.strip().split(" ")
            if parts[0] != "PROGRAM":
                for x in dic:
                    if parts[3].strip(",") == dic[x]:
                    
                        write_to_file("stacktrace_w_registers.txt",x+":"+" "+line)
                   
                     
            print(counter,parts[3])

file_name = "output_angr.csv"
second_file_name = "stacktrace_wo_registers.txt"
#dic = read_csv_file(file_name)
#check_pc(second_file_name,file_name)


#check_pc(second_file_name,file_name)
#print(dic["MPU9250_ReadAccelData"])
#print("\n")
#print(dic["MPU9250_ReadGyroData"])

drone_result(second_file_name,"Drone_regs.csv")
