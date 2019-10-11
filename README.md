# accountingsys
Vehicle Rental Accounting System Version 1.0 (2018-2019) 
Introduction
Class VEHICLE
int VId​: To store the vehicle ID
char VehicleName[20]​: To store the vehicle’s name
char EmpName[20]​: To store the driver’s name
float Dist:​ To store the distance travelled
void Enter()​: To ask the user to enter the vehicle’s details
void Display()​: To display the vehicle’s details along with fare, cost incurred to company and profit
int ReturnVId()​: To return the vehicle ID
char VName()​: To return the vehicle name
int ifare()​: To calculate and return the fare according to distance travelled
int icost()​: To calculate and return the cost incurred to company according to distance travelled
int iprofit()​: To calculate and return the profit of the company
Main function
char file[20]​: To store the file’s name
int choice​: To store the user’s choice of the function to be performed
int c​: To store user’s choice in search using vehicle name or vehicle ID and in displaying total fare, cost                                       
or profit
do...while loop​: To ask the user which function to perform and call it.
Other Functions
void EnterVName(char file[])​: To enter vehicle details into the file
void DeleteVehicle(char file[])​: To delete vehicle details for given vehicle ID
void DisplayAll(char file[])​: To display details for all registered vehicles
void SearchVId(char file[])​: To search and display details for a vehicle for given vehicle ID
void SearchVName(char file[])​: To search and display details for a vehicle for given vehicle name
void tprofit(char file[])​: To display total profit of the company
void tfare(char file[])​: To display total fare for all registered vehicles
void tcost(char file[])​: To display total cost incurred to the company
