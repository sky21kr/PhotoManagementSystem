#include"photoType.h"

// ���� �̸��� Ű����κ��� �޾� ������
void photoType::setphotoNameKB()
{
	cout <<"\t���� �̸� : ";
	cin >> photoName;
}

// ���� ���� ��¥�� Ű����κ��� �޾� ������
void photoType::setdateKB()
{
	cout << "\t���� ���� ��¥ :";
	cin >> date;
}

// ���� ũ�⸦ Ű����κ��� �޾� ������
void photoType ::setsizeKB()
{
	cout << "\t���� ũ�� : ";
	cin >> size;
}

// ���� ������ Ű����κ��� �޾� ������
void photoType ::setcontentKB()
{
	cout << "\t���� ���� : ";
	cin >> content;
}

// ���� ���� ����
void photoType ::sethide(bool temp_hide)
{
	hide = temp_hide;
}

// ���� �̸��� ����
RelationType photoType::CompareByName(const photoType &data)
{
	if(this->photoName > data.photoName)	// ���� ���� �̸��� ������ �� ������
		return GREATER;
	else if(this->photoName < data.photoName)	// ���� ���� �̸��� ������ �� ������
		return LESS;
	else	// ���� �̸��� ������ ������
		return EQUAL;
}

//	���� �̸��� �޾ƿ�
string photoType::GetName()
{
	return photoName;
}

// ������ ������ �����
void photoType::DisplayPhoto()
{
	cout << "\t���� �̸� : " << photoName << endl;
	cout << "\t���� ���� ��¥ : " << date << endl;
	cout << "\t���� ũ�� : " << size << endl;
	cout << "\t���� ���� : " << content << endl;
}

// ������ ��¥�� �޾ƿ�
string photoType::getdate()
{
	return date;
}

// ������ ����� �޾ƿ�
int photoType ::getsize()
{
	return size;
}

// ������ ������ �޾ƿ�
string photoType ::getcontent()
{
	return content;	
}

// ������� ��ȯ
bool photoType::gethide()
{
	return hide;
}

// ������ �̸��� ������
void photoType::setname(string temp_name)
{
	photoName = temp_name;
}

// ������ ��¥�� ������
void photoType ::setdate(string temp_date)
{
	date = temp_date;
}

// ������ ����� ������
void photoType ::setsize(int temp_size)
{
	size = temp_size;
}

// ������ ������ ������
void photoType::setconstent(string temp_content)
{
	content = temp_content;
}

// ������ �����ε�
bool photoType::operator>(photoType item)
{
	if( photoName > item.GetName())
	{
		return true;
	}
	else
		return false;
}

// ������ �����ε�
bool photoType::operator<(photoType item)
{
	if( photoName < item.GetName() )
	{
		return true;
	}
	else
		return false;
}

// ���ã�� ���� ��ȯ
int photoType::getbook()
{
	return book;
}

// ���ã�� ���� ����
void photoType::setbook(int temp_book)
{
	book = temp_book;
}