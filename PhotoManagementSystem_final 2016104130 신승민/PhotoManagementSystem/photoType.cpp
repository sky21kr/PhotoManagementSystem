#include"photoType.h"

// 사진 이름을 키보드로부터 받아 설정함
void photoType::setphotoNameKB()
{
	cout <<"\t사진 이름 : ";
	cin >> photoName;
}

// 사진 생성 날짜를 키보드로부터 받아 설정함
void photoType::setdateKB()
{
	cout << "\t사진 생성 날짜 :";
	cin >> date;
}

// 사진 크기를 키보드로부터 받아 설정함
void photoType ::setsizeKB()
{
	cout << "\t사진 크기 : ";
	cin >> size;
}

// 사진 내용을 키보드로부터 받아 설정함
void photoType ::setcontentKB()
{
	cout << "\t사진 내용 : ";
	cin >> content;
}

// 숨김 상태 설정
void photoType ::sethide(bool temp_hide)
{
	hide = temp_hide;
}

// 사진 이름을 비교함
RelationType photoType::CompareByName(const photoType &data)
{
	if(this->photoName > data.photoName)	// 현재 사진 이름의 순서가 더 빠르면
		return GREATER;
	else if(this->photoName < data.photoName)	// 현재 사진 이름의 순서가 더 느리면
		return LESS;
	else	// 사진 이름의 순서가 같으면
		return EQUAL;
}

//	사진 이름을 받아옴
string photoType::GetName()
{
	return photoName;
}

// 사진의 정보를 출력함
void photoType::DisplayPhoto()
{
	cout << "\t사진 이름 : " << photoName << endl;
	cout << "\t사진 생성 날짜 : " << date << endl;
	cout << "\t사진 크기 : " << size << endl;
	cout << "\t사진 내용 : " << content << endl;
}

// 사진의 날짜를 받아옴
string photoType::getdate()
{
	return date;
}

// 사진의 사이즈를 받아옴
int photoType ::getsize()
{
	return size;
}

// 사진의 내용을 받아옴
string photoType ::getcontent()
{
	return content;	
}

// 숨김상태 반환
bool photoType::gethide()
{
	return hide;
}

// 사진의 이름을 설정힘
void photoType::setname(string temp_name)
{
	photoName = temp_name;
}

// 사진의 날짜를 설정함
void photoType ::setdate(string temp_date)
{
	date = temp_date;
}

// 사진의 사이즈를 설정함
void photoType ::setsize(int temp_size)
{
	size = temp_size;
}

// 사진의 내용을 설정함
void photoType::setconstent(string temp_content)
{
	content = temp_content;
}

// 연산자 오버로딩
bool photoType::operator>(photoType item)
{
	if( photoName > item.GetName())
	{
		return true;
	}
	else
		return false;
}

// 연산자 오버로딩
bool photoType::operator<(photoType item)
{
	if( photoName < item.GetName() )
	{
		return true;
	}
	else
		return false;
}

// 즐겨찾기 상태 반환
int photoType::getbook()
{
	return book;
}

// 즐겨찾기 상태 설정
void photoType::setbook(int temp_book)
{
	book = temp_book;
}