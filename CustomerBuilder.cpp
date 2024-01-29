//Encapsulation
class Customer{
   
};

class CustomerBuilder{

};

int main(){
  Customer* customer1=new CustomerBuilder{"venu","Blr","ADDRV007","ADH546899"}->getInstance();
  Customer* customer2=new CustomerBuilder{"venu","Blr","ADDRV007","ADH546899"}->setPhone(12345)->getInstance();
  Customer* customer3=new CustomerBuilder{"venu","Blr","ADDRV007","ADH546899"}->setEmail("vgk@v.com")->getInstance();
  Customer* customer4=new CustomerBuilder{"venu","Blr","ADDRV007","ADH546899"}->setPhone("12345")->setEmail("vgk@v.com")->getInstance();

}
