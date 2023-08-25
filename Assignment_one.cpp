class ICommunicationManager{
public:
  virtual void shareContent(string imageLink)=0;
}
class ImageGallery {

string images[5] = { "one.jpg","two.jpg","three.jpg","four.jpg","fiv.jpg"};
public:void share(int index,ICommunicationManager* comManager) {
	comManager->shareContent(images[index]);
}
};

class BluetoothManager: public ICommunicationManager {
public:
	void searchDevices() {}
    void pairdevice(){}
	void sendContent() {}
	void turnOn() {}
	void turnOff(){}
void shareContent(string imageLink){   // }

};

class WhatsUpManager : public ICommunicationManager {
	void turnOn() {}
	void turnOff() {}
	void shareContent() {}
	void joinGroup() {}
	void addMember(){}
	void createGroup() {}
	void shareContent(string imageLink){   // }

};

class MailManager:public ICommunicationManager {

	void pullNewMails() {}
	void senMails(){}
	void composeEmail(){}
	void addAttachement() {}
void shareContent(string imageLink){   // }

};

int main() {

	MailManager* _mailManager = new  MailManager();
	BluetoothManager* _bluetoothManager = new  BluetoothManager();
	WhatsUpManager* _whatsUpManager = new  WhatsUpManager();
	
	ImageGallery* imageMgmt = new  ImageGallery();
	imageMgmt->share(0,_mailManager);
	imageMgmt->share(0,_bluetoothManager);
	imageMgmt->share(0,_whatsUpManager);
	
}
