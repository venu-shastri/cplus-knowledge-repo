#include <string>
#include <iostream>
#include <vector>
using namespace std;
class Paragraph;
class Link;
class Header;
class Footer;
class IDocumentConveter;
class Document;
class HtmlConverter;

class IDocumentConveter {
public:
	virtual void convert(Paragraph* paragraphPtr) = 0;
	virtual void convert(Link* linkPtr) = 0;
	virtual void convert(Header* headerPtr) = 0;
	virtual void convert(Footer* headerPtr) = 0;
};
class DocumentPart {
private: string  name;

public:
	void setName(string value) {
		this->name = value;
	}
	string getName() const { return this->name; }
	virtual void paint() = 0;
	virtual void save() = 0;
	virtual void convert(IDocumentConveter* converter) = 0;
};

class Paragraph :public DocumentPart {
private:string content;
public:
	Paragraph(string contentArg) :content(contentArg) {}
	string getContent() const { return this->content; }
	void paint() {
		cout << "Paragraph Painted" << endl;
	}
	void save() {
		cout << "Paragraph Saved" << endl;
	}
	void convert(IDocumentConveter* converter){
		converter->convert(this);
	}

};
class Link :public DocumentPart {
private: string url;
public:
	Link(string urlAddress) :url(urlAddress) {}
	string getUrl() const { return this->url; }
	void paint() {
		cout << "Link Painted" << endl;
	}
	void save() {
		cout << "Link Saved" << endl;
	}
	void convert(IDocumentConveter* converter) {
		converter->convert(this);
	}
};
class Header :public DocumentPart {
private: string text;
public:
	Header(string textArg) :text(textArg) {}
	string getText() const { return this->text; }
	void paint() {
		cout << "Header Painted" << endl;
	}
	void save() {
		cout << "Header Saved" << endl;
	}
	void convert(IDocumentConveter* converter) {
		converter->convert(this);
	}
};
class Footer :public DocumentPart {
public:
	void paint() {
		cout << "Footer Painted" << endl;
	}
	void save() {
		cout << "Footer Saved" << endl;
	}
	void convert(IDocumentConveter* converter) {
		converter->convert(this);
	}
};
//interface

class HtmlConverter:public IDocumentConveter {
public:
	void convert(Paragraph* paragraphPtr) { cout << "<p>" + paragraphPtr->getContent() + "</p>" << endl; }
	void convert(Link* linkPtr) { cout << "<a>" + linkPtr->getUrl() + "</a>" << endl; }
	void convert(Header* headerPtr) { cout << "<header>" +headerPtr->getText() + "</header>" << endl; }
	void convert(Footer* headerPtr) { cout << "<footer></header>" << endl; }
};
class Document {
private:
	vector<DocumentPart*> parts;
public:
	void addPart(DocumentPart* part) {
		parts.push_back(part);
	}
	void open() {
		//iteration
	}
	void save() {}
	void convert(IDocumentConveter* converter) {
		for (int i = 0; i < parts.size(); i++) {
			parts[i]->convert(converter);
		}
	}
};

int main() {
	DocumentPart* header = new Header("Header Content");
	DocumentPart* footer = new Footer();
	DocumentPart* paraGraph = new Paragraph("Paragraph Content");
	DocumentPart* link = new Link("www.bosch.com");

	Document docObj;
	docObj.addPart(header);
	docObj.addPart(footer);
	docObj.addPart(paraGraph);
	docObj.addPart(link);

	IDocumentConveter* converter = new HtmlConverter();
	docObj.convert(converter);

}
