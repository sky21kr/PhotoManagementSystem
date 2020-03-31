#include"folderType.h"

//현재 폴더에 폴더를 더함
void folderType::addFolder()
{
	folderType folder;
	folder.setfoldernamefromKB();
	folder.setdatefromKB();
	folder.setnumberOfItems(0);

	cout << endl;

	if( folderList.Add(folder) != 0 )
	{
		cout << "\t폴더를 생성했습니다." << endl;
		numberOfItems++;
	}
	else
		cout << "\t이미 동일한 폴더명이 존재합니다" << endl;

	cout << endl;

	system("pause");
}

// 폴더 이름을 키보드로부터 입력받음
void folderType::setfoldernamefromKB()
{
	cout << "\t폴더 이름 : ";
	cin >> foldername;
}

// 폴더 생성 날짜를 키보드로부터 입력받음
void folderType::setdatefromKB()
{
	cout << "\t폴더 생성 날짜 : ";
	cin >> date;
}

// 현재 폴더에 사진을 추가함
void folderType::addPhoto()
{
	photoType photo;
	photo.setphotoNameKB();
	photo.setdateKB();
	photo.setsizeKB();
	photo.setcontentKB();
	photo.sethide(false);
	photo.setbook(0);

	cout << endl;

	if(	photoList.Add(photo) == true ) // 동일한 사진명이 없을 시
	{
		cout << "\t사진을 추가하였습니다." << endl;
		numberOfItems++;
	}
	else
		cout << "\t동일한 사진이름이 존재합니다." << endl;

	cout << endl;
	system("pause");
	system("cls");
}

// 폴더의 이름값을 비교해서 순서를 알아냄
RelationType folderType::CompareByName(const folderType &data)
{
	if(this->foldername > data.foldername)
		return GREATER;
	else if(this->foldername < data.foldername)
		return LESS;
	else
		return EQUAL;
}

// 현재 폴더에서 사진을 삭제함
void folderType ::deletePhoto()
{
	photoType photo;
	photo.setphotoNameKB();
	
	bool found;
	photoType* tempphoto = photoList.RetrieveItem(photo, found);

	if(tempphoto != NULL )
	{
		if(photoList.DeleteItem(photo) == true && tempphoto->gethide() == false )
		{
			cout <<"\t사진 삭제에 성공했습니다." << endl;
			numberOfItems--;
		}
		else
			cout << "\t사진 삭제에 실패했습니다." << endl;
	}
	else
		cout << "\t해당 사진이 없습니다." << endl;
}

// 현재 폴더의 이름값을 받아옴
string folderType ::GetName()
{
	return foldername;
}

// 현재 폴더에 포함된 아이템 수를 받아옴
int folderType::getnumberOfItems()
{
	return numberOfItems;
}

// 현재 폴더에 포함된 파일들을 이름순으로 정렬함
void folderType :: displayFolderByName()
{
	cout << endl;
	cout << "\t현재 폴더 이름 : ";
	cout << GetName() << endl;

	cout << "\t현재 폴더에 포함된 항목 수 : ";
	cout << getnumberOfItems()-getnumberOfhide() << endl << endl;

	cout << "\t현재 폴더에 포함된 폴더들" << endl;

	folderType folder;
	int length = folderList.GetLength();
	if( length == 0 )	// 현재 폴더에 폴더가 없다면
	{
		cout << "\t - 폴더가 존재하지 않습니다." << endl << endl;	
	}
	else
	{		
		Iterator<folderType> itor(folderList);
		folder = itor.Next();
		while(itor.NextNotNull())
		{
			cout << "\t - 폴더 이름 : " << folder.GetName() << endl;
			folder = itor.Next();
		}

		cout << endl;

	}

	cout << "\t현재 폴더에 포함된 사진들" << endl;
	photoType photo;

	length = photoList.GetLength();
	if( length == 0 )	// 현재 폴더에 포함된 사진이 없다면
	{
		cout << "\t - 사진이 존재하지 않습니다." << endl;
	}
	else
	{	
		photoList.PrintTree(false);
	}
}

// 현재 폴더의 이름을 설정함
void folderType::setfoldername(string name)
{
	foldername = name;
}

// 현재 폴더의 아이템 수를 설정함
void folderType::setnumberOfItems(int number)
{
	numberOfItems = number;
}

// 현재 폴더를 이동함
folderType* folderType::moveFolder()
{
	folderType folder;
	folder.setfoldernamefromKB();
	int Where = folderList.GetByBinarySearch(folder);	// 폴더를 찾으면 폴더 위치를 리턴함 못찾으면 -1 리턴
	if( Where != -1 )
	{
		return folderList.GetLinkedList(Where);
	}
	else
		return NULL;
}

// 현재 폴더의 폴더를 이름으로 찾아서 정보를 출력함 키워드가 포함되어있으면 출력
void folderType::FindFolder()
{
	string name;
	cout << "\t이름에 포함된 키워드 : ";
	cin >> name;

	for( int i = 1; i < folderList.GetLength()+1 ; i++)
	{
		if( folderList.GetLinkedList(i)->GetName().find(name) != string::npos )	//키워드가 포함되면 출력
		{
			cout << "\t찾았습니다." << endl << endl;
			folderList.GetLinkedList(i)->DisplayFolderRecordOnScreen();
		}
	}
}
// 현재 폴더의 정보를 출력함
void folderType::DisplayFolderRecordOnScreen()
{
	cout << "\t폴더 이름 : " << GetName() << endl;
	cout << "\t폴더 생성 날짜 : " << getdate() << endl;
	cout << "\t폴더에 포함된 파일 수 : " << getnumberOfItems()-getnumberOfhide() << endl;
}

// 현재 폴더의 생성 날짜를 받아옴
string folderType::getdate()
{
	return date;
}

// 현재 폴더의 사진을 이름으로 검색해 정보를 출력함 
void folderType ::FindPhoto()
{
	string name;
	cout << "\t찾을 사진 이름 : ";
	cin >> name;

	photoType photo;
	photo.setname(name);

	bool found;
	photoType* p_tempPhoto;
	p_tempPhoto = photoList.RetrieveItem(photo,found);
	if( found == true && p_tempPhoto->gethide() == false )
	{
		cout << endl;
		photo.DisplayPhoto();
	}
	else
		cout << "\t찾지 못했습니다." << endl;
}

// 전체 폴더의 폴더를 검색해 정보를 출력함
void  folderType::FindFolderAll(folderType namefolder)
{
	for( int i = 1 ; i < folderList.GetLength()+1 ; i++ )	// 링크드 리스트는 0이아니라 1부터 데이터 넣어서 1씩 더해줌
	{	// 폴더 구석구석을 조사하기 위한 반복문 하위폴더를 다 훑는다.
		if(folderList.GetLinkedList(i)->GetName().find(namefolder.GetName()) != string::npos )//  이름만 있는 폴더로 검색. 키워드가 포함되면 출력
		{
			cout << endl;
			cout << "\t폴더가 있는 폴더 이름 : " << (*this).GetName() << endl;	// 찾은 폴더가 있는 폴더 이름 출력
			folderList.GetLinkedList(i)->DisplayFolderRecordOnScreen();	// 찾은 폴더의 정보 출력
		}
		folderList.GetLinkedList(i)->FindFolderAll(namefolder);	// 폴더를 이동해서 다시 검색
	}
}

// 전체 폴더의 사진을 검색해 정보를 출력함
void folderType::FindPhotoAll(photoType namephoto)
{
	bool found;
	photoType* p_tempPhoto;
	p_tempPhoto = photoList.RetrieveItem(namephoto, found);
	if( found == true && p_tempPhoto->gethide() == false )
	{
		cout << endl;
		cout << "\t사진이 있는 폴더 이름 : " << (*this).GetName() << endl;	// 찾은 사진이 있는 폴더 이름 출력
		namephoto.DisplayPhoto();
	}

	for( int i = 1 ; i < folderList.GetLength()+1 ; i++ )	// 링크드 리스트는 0이아니라 1부터 데이터 넣어서 1씩 더해줌
	{	// 폴더 구석구석을 조사하기 위한 반복문 하위폴더를 다 훑는다.
		folderList.GetLinkedList(i)->FindPhotoAll(namephoto);	// 폴더를 이동해서 다시 검색
	}
}

// 데이터를 파일에 씀
void folderType::WriteFolder(ofstream& WF)
{
	folderType tempFolder;
	photoType tempPhoto;

	WF	<< folderList.GetLength() << "	" << photoList.GetLength() << "	" << getnumberOfhide() << endl;
	for( int i = 1 ; i < folderList.GetLength()+1 ; i++ )	// 링크드 리스트는 0이아니라 1부터 데이터 넣어서 1씩 더해줌
	{	// 폴더를 쭉 쓰기 위한 반복문.
		tempFolder = *folderList.GetLinkedList(i);
		WF << tempFolder.GetName() << "	" << tempFolder.getdate() << "	" << tempFolder.getnumberOfItems() << endl;
	}

	for( int i = 0 ; i < photoList.GetLength() ; i++ )
	{
		tempPhoto = photoList.ReturnData(i);
		WF << tempPhoto.GetName() << "	" << tempPhoto.getdate() << "	" << tempPhoto.getsize() << "	" << tempPhoto.getcontent();
		if( tempPhoto.gethide() == false )
			WF << "	" << 0;
		else
			WF << "	" << 1;
		WF << "	" << tempPhoto.getbook() << endl;
	}

	for( int i = 1 ; i < folderList.GetLength()+1 ; i++ )
	{
		WF << endl;
		folderList.GetLinkedList(i)->WriteFolder(WF);	// 폴더를 이동해서 다시 검색
	}
}

// 파일로부터 데이터를 읽어옴
void folderType::ReadFolder(ifstream& RF, MaxHeap<photoType*> &bookmark)
{
	int numberOfFolders;
	int numberOfPhotos;
	int numberOfhide;
	
	RF >> numberOfFolders >> numberOfPhotos >> numberOfhide;	// 처음 폴더의 개수, 사진의 개수 읽어옴

	setnumberOfhide(numberOfhide);

	folderType folder;

	string temp_folderName;
	string temp_folderDate;
	int temp_numberOfItems;

	for( int i = 0 ; i < numberOfFolders ; i++ )	// 폴더를 쭉 읽어옴
	{
		RF >> temp_folderName >> temp_folderDate >> temp_numberOfItems;
		folder.setfoldername(temp_folderName);
		folder.setdate(temp_folderDate);
		folder.setnumberOfItems(temp_numberOfItems);
		folderList.Add(folder);	// 정보 받아와서 폴더 추가
	}

	photoType photo;

	string temp_photoName;
	string temp_photoDate;
	int temp_size;
	string temp_content;
	int temp_hide;
	int temp_book;

	for( int i = 0 ; i < numberOfPhotos ; i++ )	// 사진을 쭉 읽어옴
	{
		RF >> temp_photoName >> temp_photoDate >> temp_size >> temp_content >> temp_hide >> temp_book;
		photo.setname(temp_photoName);
		photo.setdate(temp_photoDate);
		photo.setsize(temp_size);
		photo.setconstent(temp_content);
		
		if( temp_hide == 0 )
			photo.sethide(false);
		if( temp_hide == 1 )
			photo.sethide(true);

		photo.setbook(temp_book);
		
		photoList.Add(photo);	// 정보 받아와서 사진 추가
		
		if( temp_book == 1 )
		{
			bool found;
			bookmark.Put( photoList.RetrieveItem(photo,found) );
		}
	}

	for( int i = 1 ; i < numberOfFolders+1 ; i++ )
	{
		folderList.GetLinkedList(i)->ReadFolder(RF,bookmark);	// 폴더를 이동해서 다시 읽기
	}

	setnumberOfItems( numberOfFolders + numberOfPhotos );	// 현재 폴더에 포함된 것 다시 써줌
}

// 폴더의 생성날짜를 설정함 
void folderType::setdate(string temp_date)
{
	date = temp_date;
}

// 폴더의 이름을 수정함
void folderType::ModifyFolderName()
{
	folderType folder;
	folder.setfoldernamefromKB();	//사용자에게서 Name값을 입력받는다.

	folderType* tempFolder;

	int temp = folderList.GetByBinarySearch(folder);	//Name값만 가진 folder를 GetByBinarySearch으로 보내 검색한다

	if( temp != -1 )
	{
		cout << "\t찾았습니다." << endl << endl;
		tempFolder = folderList.GetLinkedList(temp);
		cout << "\t- 폴더 이름 변경" << endl;
		tempFolder->setfoldernamefromKB();
		cout << "\t수정이 완료되었습니다." << endl;
	}
	else
		cout << "\t찾지 못했습니다." << endl;
}


// 사진의 정보를 변경함 순서를 고려하기 위해 삭제후 더함
void folderType::ModifyPhoto()
{
	photoType photo;
	photo.setphotoNameKB();	//사용자에게서 Name값을 입력받는다.

	bool found;
	photoType* tempPhoto;
	tempPhoto = photoList.RetrieveItem(photo,found);	//Name값만 가진 photo로 검색한다.

	if( found == true && tempPhoto->gethide() == false )
	{
		cout << "\t찾았습니다." << endl << endl;
		photoList.DeleteItem(photo);
		cout << "\t- 사진 이름 변경" << endl;
		photo.setphotoNameKB();
		photoList.Add(photo);
		cout << "\t수정이 완료되었습니다." << endl;
		return;
	}
	else
		cout << "\t찾지 못했습니다." << endl;
}

// 폴더를 삭제한다
void folderType ::deleteFolder()
{
	folderType folder;
	folder.setfoldernamefromKB();	//사용자에게서 Name값을 입력받는다.

	folderType* tempFolder;

	cout << endl;

	int temp = folderList.GetByBinarySearch(folder);
	if( temp != -1 )	//Name값만 가진 folder를 GetByBinarySearch으로 보내 검색한다
	{
		cout << "\t찾았습니다." << endl << endl;

		tempFolder = folderList.GetLinkedList(temp);

		tempFolder->deleteAllFolder();	// 폴더의 하위항목들을 모두 삭제한다

		folderList.Delete(folder);	// 폴더를 삭제한다.

		numberOfItems--;

		cout << "\t삭제가 완료되었습니다." << endl;
	}
	else
		cout << "\t찾지 못했습니다." << endl;
}

// 하위 항목들을 모두 삭제함
void folderType ::deleteAllFolder()
{
	photoList.MakeEmpty(); // 우선 사진은 바로 삭제한다.

	for( int i = 1 ; i < folderList.GetLength()+1 ; i++ )
	{
		folderList.GetLinkedList(i)->deleteAllFolder();	// 폴더 구석구석을 탐색하여 삭제
	}
	
	folderList.MakeEmpty();	// 하위폴더가 없는 곳 까지 들어가서 삭제한다.

}

// 즐겨찾기 추가
void folderType::bookmarkAdd_F(MaxHeap<photoType*> &bookmark)
{
	string name;
	cout << "\t즐겨찾기에 추가할 사진 이름 : ";
	cin >> name;

	photoType photo;
	photo.setname(name);

	bool found;

	photoType* p_tempPhoto;
	p_tempPhoto = photoList.RetrieveItem(photo,found);

	if( found == true && p_tempPhoto->gethide() == false )	// 찾고 사진이 숨김 상태가 아니면
	{
		if( p_tempPhoto->getbook() == 1 )	// 이미 즐겨찾기 목록에 있으면
		{
			cout << "\t이미 즐겨찾기 목록에 있습니다." << endl;
		}
		else if( bookmark.Put(p_tempPhoto) == 0 )	// 즐겨찾기 목록이 꽉 차면
		{
			cout << "\t즐겨찾기 목록이 꽉 찼습니다." << endl;
		}
		else
		{
			p_tempPhoto->setbook(1);	// 즐겨찾기에 있는 상태로
			cout << "\t즐겨찾기 목록에 사진을 추가했습니다." << endl;
			cout << endl;
			bookmark.PrintHeap();
		}
	}
	else
		cout << "\t찾지 못했습니다." << endl;
}

// 사진 잘라내기
bool folderType::cutoff_F(photoType &tempPhoto)
{
	bool found;
	tempPhoto.setphotoNameKB();

	photoType* p_tempPhoto;

	p_tempPhoto = photoList.RetrieveItem(tempPhoto,found);

	if( found == false || p_tempPhoto->gethide() == true )
	{
		cout << "\t사진이 존재하지 않습니다." << endl;
		return false;
	}
	else
	{
		cout << "\t사진을 잘라냈습니다." << endl;
		photoList.DeleteItem(tempPhoto);
		return true;
	}
}

// 사진 붙여넣기
bool folderType::paste_F(photoType tempPhoto)
{
	if(photoList.Add(tempPhoto) == true)
	{
		cout << "\t붙여넣기에 성공하였습니다." << endl;
		return true;	
	}
	else
	{
		cout << "\t이미 동일한 이름의 사진이 존재합니다. 붙여넣기에 실패하였습니다." << endl;
		return false;
	}
}

// 사진 숨기기
void folderType::hidePhoto_F()
{
	bool found;
	photoType tempPhoto;
	photoType* p_tempPhoto;
	tempPhoto.setphotoNameKB();

	p_tempPhoto = photoList.RetrieveItem(tempPhoto,found);

	if( found == true && p_tempPhoto->gethide() == false )
	{
		p_tempPhoto->sethide(true);
		numberOfhide++;
		cout << "\t사진을 숨겼습니다." << endl;
	}
	else
	{
		cout << "\t사진을 찾지 못했습니다." << endl;
	}
}

// 사진 숨김 상태 해제
void folderType::un_hidePhoto_F()
{
	bool found;
	photoType tempPhoto;
	photoType* p_tempPhoto;
	tempPhoto.setphotoNameKB();

	p_tempPhoto = photoList.RetrieveItem(tempPhoto,found);

	if( found == true && p_tempPhoto->gethide() == true )
	{
		p_tempPhoto->sethide(false);
		numberOfhide;
		cout << "\t사진 숨김을 해제하였습니다." << endl;
	}
	else if( found == true && p_tempPhoto->gethide() == false )
	{
		cout << "\t해당 사진은 숨김 상태가 아닙니다." << endl;
	}
	else
		cout << "\t해당 사진이 없습니다." << endl;
}

// 숨긴 상태인 사진들 출력
void folderType::print_hidePhoto_F()
{
	photoList.PrintTree(true);
}

// 숨긴 상태의 사진수 설정
void folderType::setnumberOfhide(int m_setnumberOfhide)
{
	numberOfhide = m_setnumberOfhide;	
}

// 숨긴 상태의 사진수 받아옴
int folderType::getnumberOfhide()
{
	return numberOfhide;
}