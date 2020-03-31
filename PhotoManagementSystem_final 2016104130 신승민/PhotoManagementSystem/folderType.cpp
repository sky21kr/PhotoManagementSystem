#include"folderType.h"

//���� ������ ������ ����
void folderType::addFolder()
{
	folderType folder;
	folder.setfoldernamefromKB();
	folder.setdatefromKB();
	folder.setnumberOfItems(0);

	cout << endl;

	if( folderList.Add(folder) != 0 )
	{
		cout << "\t������ �����߽��ϴ�." << endl;
		numberOfItems++;
	}
	else
		cout << "\t�̹� ������ �������� �����մϴ�" << endl;

	cout << endl;

	system("pause");
}

// ���� �̸��� Ű����κ��� �Է¹���
void folderType::setfoldernamefromKB()
{
	cout << "\t���� �̸� : ";
	cin >> foldername;
}

// ���� ���� ��¥�� Ű����κ��� �Է¹���
void folderType::setdatefromKB()
{
	cout << "\t���� ���� ��¥ : ";
	cin >> date;
}

// ���� ������ ������ �߰���
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

	if(	photoList.Add(photo) == true ) // ������ �������� ���� ��
	{
		cout << "\t������ �߰��Ͽ����ϴ�." << endl;
		numberOfItems++;
	}
	else
		cout << "\t������ �����̸��� �����մϴ�." << endl;

	cout << endl;
	system("pause");
	system("cls");
}

// ������ �̸����� ���ؼ� ������ �˾Ƴ�
RelationType folderType::CompareByName(const folderType &data)
{
	if(this->foldername > data.foldername)
		return GREATER;
	else if(this->foldername < data.foldername)
		return LESS;
	else
		return EQUAL;
}

// ���� �������� ������ ������
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
			cout <<"\t���� ������ �����߽��ϴ�." << endl;
			numberOfItems--;
		}
		else
			cout << "\t���� ������ �����߽��ϴ�." << endl;
	}
	else
		cout << "\t�ش� ������ �����ϴ�." << endl;
}

// ���� ������ �̸����� �޾ƿ�
string folderType ::GetName()
{
	return foldername;
}

// ���� ������ ���Ե� ������ ���� �޾ƿ�
int folderType::getnumberOfItems()
{
	return numberOfItems;
}

// ���� ������ ���Ե� ���ϵ��� �̸������� ������
void folderType :: displayFolderByName()
{
	cout << endl;
	cout << "\t���� ���� �̸� : ";
	cout << GetName() << endl;

	cout << "\t���� ������ ���Ե� �׸� �� : ";
	cout << getnumberOfItems()-getnumberOfhide() << endl << endl;

	cout << "\t���� ������ ���Ե� ������" << endl;

	folderType folder;
	int length = folderList.GetLength();
	if( length == 0 )	// ���� ������ ������ ���ٸ�
	{
		cout << "\t - ������ �������� �ʽ��ϴ�." << endl << endl;	
	}
	else
	{		
		Iterator<folderType> itor(folderList);
		folder = itor.Next();
		while(itor.NextNotNull())
		{
			cout << "\t - ���� �̸� : " << folder.GetName() << endl;
			folder = itor.Next();
		}

		cout << endl;

	}

	cout << "\t���� ������ ���Ե� ������" << endl;
	photoType photo;

	length = photoList.GetLength();
	if( length == 0 )	// ���� ������ ���Ե� ������ ���ٸ�
	{
		cout << "\t - ������ �������� �ʽ��ϴ�." << endl;
	}
	else
	{	
		photoList.PrintTree(false);
	}
}

// ���� ������ �̸��� ������
void folderType::setfoldername(string name)
{
	foldername = name;
}

// ���� ������ ������ ���� ������
void folderType::setnumberOfItems(int number)
{
	numberOfItems = number;
}

// ���� ������ �̵���
folderType* folderType::moveFolder()
{
	folderType folder;
	folder.setfoldernamefromKB();
	int Where = folderList.GetByBinarySearch(folder);	// ������ ã���� ���� ��ġ�� ������ ��ã���� -1 ����
	if( Where != -1 )
	{
		return folderList.GetLinkedList(Where);
	}
	else
		return NULL;
}

// ���� ������ ������ �̸����� ã�Ƽ� ������ ����� Ű���尡 ���ԵǾ������� ���
void folderType::FindFolder()
{
	string name;
	cout << "\t�̸��� ���Ե� Ű���� : ";
	cin >> name;

	for( int i = 1; i < folderList.GetLength()+1 ; i++)
	{
		if( folderList.GetLinkedList(i)->GetName().find(name) != string::npos )	//Ű���尡 ���ԵǸ� ���
		{
			cout << "\tã�ҽ��ϴ�." << endl << endl;
			folderList.GetLinkedList(i)->DisplayFolderRecordOnScreen();
		}
	}
}
// ���� ������ ������ �����
void folderType::DisplayFolderRecordOnScreen()
{
	cout << "\t���� �̸� : " << GetName() << endl;
	cout << "\t���� ���� ��¥ : " << getdate() << endl;
	cout << "\t������ ���Ե� ���� �� : " << getnumberOfItems()-getnumberOfhide() << endl;
}

// ���� ������ ���� ��¥�� �޾ƿ�
string folderType::getdate()
{
	return date;
}

// ���� ������ ������ �̸����� �˻��� ������ ����� 
void folderType ::FindPhoto()
{
	string name;
	cout << "\tã�� ���� �̸� : ";
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
		cout << "\tã�� ���߽��ϴ�." << endl;
}

// ��ü ������ ������ �˻��� ������ �����
void  folderType::FindFolderAll(folderType namefolder)
{
	for( int i = 1 ; i < folderList.GetLength()+1 ; i++ )	// ��ũ�� ����Ʈ�� 0�̾ƴ϶� 1���� ������ �־ 1�� ������
	{	// ���� ���������� �����ϱ� ���� �ݺ��� ���������� �� �ȴ´�.
		if(folderList.GetLinkedList(i)->GetName().find(namefolder.GetName()) != string::npos )//  �̸��� �ִ� ������ �˻�. Ű���尡 ���ԵǸ� ���
		{
			cout << endl;
			cout << "\t������ �ִ� ���� �̸� : " << (*this).GetName() << endl;	// ã�� ������ �ִ� ���� �̸� ���
			folderList.GetLinkedList(i)->DisplayFolderRecordOnScreen();	// ã�� ������ ���� ���
		}
		folderList.GetLinkedList(i)->FindFolderAll(namefolder);	// ������ �̵��ؼ� �ٽ� �˻�
	}
}

// ��ü ������ ������ �˻��� ������ �����
void folderType::FindPhotoAll(photoType namephoto)
{
	bool found;
	photoType* p_tempPhoto;
	p_tempPhoto = photoList.RetrieveItem(namephoto, found);
	if( found == true && p_tempPhoto->gethide() == false )
	{
		cout << endl;
		cout << "\t������ �ִ� ���� �̸� : " << (*this).GetName() << endl;	// ã�� ������ �ִ� ���� �̸� ���
		namephoto.DisplayPhoto();
	}

	for( int i = 1 ; i < folderList.GetLength()+1 ; i++ )	// ��ũ�� ����Ʈ�� 0�̾ƴ϶� 1���� ������ �־ 1�� ������
	{	// ���� ���������� �����ϱ� ���� �ݺ��� ���������� �� �ȴ´�.
		folderList.GetLinkedList(i)->FindPhotoAll(namephoto);	// ������ �̵��ؼ� �ٽ� �˻�
	}
}

// �����͸� ���Ͽ� ��
void folderType::WriteFolder(ofstream& WF)
{
	folderType tempFolder;
	photoType tempPhoto;

	WF	<< folderList.GetLength() << "	" << photoList.GetLength() << "	" << getnumberOfhide() << endl;
	for( int i = 1 ; i < folderList.GetLength()+1 ; i++ )	// ��ũ�� ����Ʈ�� 0�̾ƴ϶� 1���� ������ �־ 1�� ������
	{	// ������ �� ���� ���� �ݺ���.
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
		folderList.GetLinkedList(i)->WriteFolder(WF);	// ������ �̵��ؼ� �ٽ� �˻�
	}
}

// ���Ϸκ��� �����͸� �о��
void folderType::ReadFolder(ifstream& RF, MaxHeap<photoType*> &bookmark)
{
	int numberOfFolders;
	int numberOfPhotos;
	int numberOfhide;
	
	RF >> numberOfFolders >> numberOfPhotos >> numberOfhide;	// ó�� ������ ����, ������ ���� �о��

	setnumberOfhide(numberOfhide);

	folderType folder;

	string temp_folderName;
	string temp_folderDate;
	int temp_numberOfItems;

	for( int i = 0 ; i < numberOfFolders ; i++ )	// ������ �� �о��
	{
		RF >> temp_folderName >> temp_folderDate >> temp_numberOfItems;
		folder.setfoldername(temp_folderName);
		folder.setdate(temp_folderDate);
		folder.setnumberOfItems(temp_numberOfItems);
		folderList.Add(folder);	// ���� �޾ƿͼ� ���� �߰�
	}

	photoType photo;

	string temp_photoName;
	string temp_photoDate;
	int temp_size;
	string temp_content;
	int temp_hide;
	int temp_book;

	for( int i = 0 ; i < numberOfPhotos ; i++ )	// ������ �� �о��
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
		
		photoList.Add(photo);	// ���� �޾ƿͼ� ���� �߰�
		
		if( temp_book == 1 )
		{
			bool found;
			bookmark.Put( photoList.RetrieveItem(photo,found) );
		}
	}

	for( int i = 1 ; i < numberOfFolders+1 ; i++ )
	{
		folderList.GetLinkedList(i)->ReadFolder(RF,bookmark);	// ������ �̵��ؼ� �ٽ� �б�
	}

	setnumberOfItems( numberOfFolders + numberOfPhotos );	// ���� ������ ���Ե� �� �ٽ� ����
}

// ������ ������¥�� ������ 
void folderType::setdate(string temp_date)
{
	date = temp_date;
}

// ������ �̸��� ������
void folderType::ModifyFolderName()
{
	folderType folder;
	folder.setfoldernamefromKB();	//����ڿ��Լ� Name���� �Է¹޴´�.

	folderType* tempFolder;

	int temp = folderList.GetByBinarySearch(folder);	//Name���� ���� folder�� GetByBinarySearch���� ���� �˻��Ѵ�

	if( temp != -1 )
	{
		cout << "\tã�ҽ��ϴ�." << endl << endl;
		tempFolder = folderList.GetLinkedList(temp);
		cout << "\t- ���� �̸� ����" << endl;
		tempFolder->setfoldernamefromKB();
		cout << "\t������ �Ϸ�Ǿ����ϴ�." << endl;
	}
	else
		cout << "\tã�� ���߽��ϴ�." << endl;
}


// ������ ������ ������ ������ ����ϱ� ���� ������ ����
void folderType::ModifyPhoto()
{
	photoType photo;
	photo.setphotoNameKB();	//����ڿ��Լ� Name���� �Է¹޴´�.

	bool found;
	photoType* tempPhoto;
	tempPhoto = photoList.RetrieveItem(photo,found);	//Name���� ���� photo�� �˻��Ѵ�.

	if( found == true && tempPhoto->gethide() == false )
	{
		cout << "\tã�ҽ��ϴ�." << endl << endl;
		photoList.DeleteItem(photo);
		cout << "\t- ���� �̸� ����" << endl;
		photo.setphotoNameKB();
		photoList.Add(photo);
		cout << "\t������ �Ϸ�Ǿ����ϴ�." << endl;
		return;
	}
	else
		cout << "\tã�� ���߽��ϴ�." << endl;
}

// ������ �����Ѵ�
void folderType ::deleteFolder()
{
	folderType folder;
	folder.setfoldernamefromKB();	//����ڿ��Լ� Name���� �Է¹޴´�.

	folderType* tempFolder;

	cout << endl;

	int temp = folderList.GetByBinarySearch(folder);
	if( temp != -1 )	//Name���� ���� folder�� GetByBinarySearch���� ���� �˻��Ѵ�
	{
		cout << "\tã�ҽ��ϴ�." << endl << endl;

		tempFolder = folderList.GetLinkedList(temp);

		tempFolder->deleteAllFolder();	// ������ �����׸���� ��� �����Ѵ�

		folderList.Delete(folder);	// ������ �����Ѵ�.

		numberOfItems--;

		cout << "\t������ �Ϸ�Ǿ����ϴ�." << endl;
	}
	else
		cout << "\tã�� ���߽��ϴ�." << endl;
}

// ���� �׸���� ��� ������
void folderType ::deleteAllFolder()
{
	photoList.MakeEmpty(); // �켱 ������ �ٷ� �����Ѵ�.

	for( int i = 1 ; i < folderList.GetLength()+1 ; i++ )
	{
		folderList.GetLinkedList(i)->deleteAllFolder();	// ���� ���������� Ž���Ͽ� ����
	}
	
	folderList.MakeEmpty();	// ���������� ���� �� ���� ���� �����Ѵ�.

}

// ���ã�� �߰�
void folderType::bookmarkAdd_F(MaxHeap<photoType*> &bookmark)
{
	string name;
	cout << "\t���ã�⿡ �߰��� ���� �̸� : ";
	cin >> name;

	photoType photo;
	photo.setname(name);

	bool found;

	photoType* p_tempPhoto;
	p_tempPhoto = photoList.RetrieveItem(photo,found);

	if( found == true && p_tempPhoto->gethide() == false )	// ã�� ������ ���� ���°� �ƴϸ�
	{
		if( p_tempPhoto->getbook() == 1 )	// �̹� ���ã�� ��Ͽ� ������
		{
			cout << "\t�̹� ���ã�� ��Ͽ� �ֽ��ϴ�." << endl;
		}
		else if( bookmark.Put(p_tempPhoto) == 0 )	// ���ã�� ����� �� ����
		{
			cout << "\t���ã�� ����� �� á���ϴ�." << endl;
		}
		else
		{
			p_tempPhoto->setbook(1);	// ���ã�⿡ �ִ� ���·�
			cout << "\t���ã�� ��Ͽ� ������ �߰��߽��ϴ�." << endl;
			cout << endl;
			bookmark.PrintHeap();
		}
	}
	else
		cout << "\tã�� ���߽��ϴ�." << endl;
}

// ���� �߶󳻱�
bool folderType::cutoff_F(photoType &tempPhoto)
{
	bool found;
	tempPhoto.setphotoNameKB();

	photoType* p_tempPhoto;

	p_tempPhoto = photoList.RetrieveItem(tempPhoto,found);

	if( found == false || p_tempPhoto->gethide() == true )
	{
		cout << "\t������ �������� �ʽ��ϴ�." << endl;
		return false;
	}
	else
	{
		cout << "\t������ �߶�½��ϴ�." << endl;
		photoList.DeleteItem(tempPhoto);
		return true;
	}
}

// ���� �ٿ��ֱ�
bool folderType::paste_F(photoType tempPhoto)
{
	if(photoList.Add(tempPhoto) == true)
	{
		cout << "\t�ٿ��ֱ⿡ �����Ͽ����ϴ�." << endl;
		return true;	
	}
	else
	{
		cout << "\t�̹� ������ �̸��� ������ �����մϴ�. �ٿ��ֱ⿡ �����Ͽ����ϴ�." << endl;
		return false;
	}
}

// ���� �����
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
		cout << "\t������ ������ϴ�." << endl;
	}
	else
	{
		cout << "\t������ ã�� ���߽��ϴ�." << endl;
	}
}

// ���� ���� ���� ����
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
		cout << "\t���� ������ �����Ͽ����ϴ�." << endl;
	}
	else if( found == true && p_tempPhoto->gethide() == false )
	{
		cout << "\t�ش� ������ ���� ���°� �ƴմϴ�." << endl;
	}
	else
		cout << "\t�ش� ������ �����ϴ�." << endl;
}

// ���� ������ ������ ���
void folderType::print_hidePhoto_F()
{
	photoList.PrintTree(true);
}

// ���� ������ ������ ����
void folderType::setnumberOfhide(int m_setnumberOfhide)
{
	numberOfhide = m_setnumberOfhide;	
}

// ���� ������ ������ �޾ƿ�
int folderType::getnumberOfhide()
{
	return numberOfhide;
}