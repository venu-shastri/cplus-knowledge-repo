class ImageGallery {
	string images[5] = { "one.jpg","two.jpg","three.jpg","four.jpg","fiv.jpg"};
public:void share(int index) {



}
};

class BluetoothManager{
public:
	void searchDevices() {}
    void pairdevice(){}
	void sendContent() {}
	void turnOn() {}
	void turnOff(){}

};

class WhatsUpManager {
	void turnOn() {}
	void turnOff() {}
	void shareContent() {}
	void joinGroup() {}
	void addMember(){}
	void createGroup() {}


};

class MailManager {

	void pullNewMails() {}
	void senMails(){}
	void composeEmail(){}
	void addAttachement() {}

};

int main() {

	MailManager* _mailManager = new  MailManager();
	BluetoothManager* _mailManager = new  BluetoothManager();
	WhatsUpManager* _mailManager = new  WhatsUpManager();
	
	ImageGallery* imageMgmt = new  ImageGallery();
	imageMgmt->share(0);
	
}
