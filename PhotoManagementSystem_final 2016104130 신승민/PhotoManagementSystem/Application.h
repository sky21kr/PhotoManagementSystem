#pragma once
#include "SortedList.h"
#include "folderType.h"
#include "Stack.h"
#include "heap_recursive.h"

/**
*	���� ������ ���� Applicaiton class
*/
class Application
{
public:
	/**
	*	�⺻ ������
	*/
	Application()
	{
		curFolder = &photoalbum;					// ���� ���� �ּҸ� ����
		curFolder->setfoldername("PhotoAlbum");	// ���� ���� �̸� ����
		curFolder->setnumberOfItems(0);		// ���� ������ ������ ���� ����
		Is_tempPhoto = false;	// ���� ���� ��
	}

	/**
	*	�Ҹ���
	*/
	~Application()
	{
	}

	/**
	*	@brief	���α׷� �۵�
	*	@pre	���α׷� ���� ��
	*	@post	���α׷��� �����
	*/
	void Run();

	/**
	*	@brief	Ŀ�ǵ� �����ְ� ����ڷκ��� Ű �Է¹ޱ�
	*	@pre	����
	*	@post	����
	*	@return �Է��� Ű
	*/
	int GetCommand();

	/**
	*	@brief	���� ������ ������ ����
	*	@pre	curFolder�� �ʱ�ȭ �Ǿ��� �־����
	*	@post	curFolder�� addFolder()�� �ҷ���
	*/
	void addFolderInterface();

	/**
	*	@brief	���� ������ ������ ����
	*	@pre	curFolder�� �ʱ�ȭ �Ǿ��� �־����
	*	@post	curFolder�� addPhoto()�� �ҷ���
	*/
	void addPhotoInterface();

	/**
	*	@brief	���� ������ ������ ������
	*	@pre	curFolder�� �ʱ�ȭ �Ǿ��� �־����
	*	@post	curFolder�� deleteFolder()�� �ҷ���
	*/
	void deleteFolderInterface();

	/**
	*	@brief	���� ������ ������ ������
	*	@pre	curFolder�� �ʱ�ȭ �Ǿ��� �־����
	*	@post	curFolder�� deletePhoto()�� �ҷ���
	*/
	void deletePhotoInterface();

	/**
	*	@brief	���� ������ ���� ������� ������� ������ �̸������� ������
	*	@pre	curFolder�� �ʱ�ȭ �Ǿ��� �־����
	*	@post	����
	*/
	void displayCurFolderByName();	
	
	/**
	*	@brief	���� ������ �̵���
	*	@pre	curFolder�� �ʱ�ȭ �Ǿ��� �־����
	*	@post	curFolder�� �ּҰ��� �ٲ�� ���� �ܰ谡 �Ѵܰ� ������
	*/
	void moveCurFolder();

	/**
	*	@brief	���� ������ ���ư�
	*	@pre	curFolder�� �ʱ�ȭ �Ǿ��� �־����
	*	@post	curFolder�� �ּҰ��� �ٲ�� ���� �ܰ谡 �Ѵܰ� ������
	*/
	void backFolder();

	/**
	*	@brief	������ ������ �̸����� �˻��� Ű���尡 ���ԵǸ� ���
	*	@pre	���� ������ �ʱ�ȭ �Ǿ��� �־����
	*	@post	����
	*/
	void FindNDisplayFolder();

	/**
	*	@brief	������ ������ �̸����� �˻��� Ű���尡 ���ԵǸ� ���
	*	@pre	���� ������ �ʱ�ȭ �Ǿ��� �־����
	*	@post	����
	*/
	void FindNDisplayPhoto();

		/**
	*	@brief	���Ͽ� �������� ���� ��ũ���ͷ� ������ ����
	*	@pre	�б� ���� ������ �����ؾ��մϴ�
	*	@post	�б� ���� ������ ������
	*	@param	fileName	�б� ���� ������ �̸�
	*	@return	����� �۵��ϸ� 1, �׷��� ������ 0 ����
	*/
	int OpenInFile(char *fileName);

	/**
	*	@brief	�о� �������� ���� ��ũ���ͷ� ������ ����
	*	@pre	����Ʈ�� �ʱ�ȭ �Ǿ��� �־����
	*	@post	���� ���� ������ ����
	*	@param	fileName	���� ���� ������ �� ���� �̸�
	*	@return	����� �۵��ϸ� 1, �׷��� ������ 0�� ����
	*/
	int OpenOutFile(char *fileName);

	/**
	*	@brief	�б� ���� ������ ���� ������ ��� �����͸� �а� �� �����͸� ����Ʈ�� �ִ´�
	*	@pre	�� ������ �������� �ʴ�.
	*	@post	���Ϸ� �� ����Ʈ�� ��� �����͸� �޾ƿ´�
	*	@return	����� �۵��ϸ� 1, �׷��� ������ 0�� ����
	*/
	int ReadDataFromFile();

	/**
	*	@brief	������ �б� ���� ���� ��� �����͸� �� ���Ͽ� ����
	*	@pre	�� ������ �������� �ʴ�
	*	@post	���� ���Ͽ� ����Ʈ�� ����ȴ�.
	*	@return	����� �۵��ϸ� 1, �׷��� ������ 0�� ����
	*/
	int WriteDataToFile();

	/**
	*	@brief	������ �̸��� �����Ѵ�.
	*	@pre	������ ������� �־����
	*	@post	������ �̸��� �ٲ��.
	*/
	void ModifyFoldrName();
	
	/**
	*	@brief	������ ������ �����Ѵ�.
	*	@pre	������ ������� �־����.
	*	@post	������ ������ �ٲ��.
	*/
	void ModifyPhoto();

	/**
	*	@brief	��й�ȣ�� �����Ѵ�
	*	@pre	login.txt������ ������� �־���Ѵ�.
	*	@post	login.txt�� ��й�ȣ�� �ٲ��.
	*/
	void changePassword();

	/**
	*	@brief	���α׷��� �α��� �Ѵ�.
	*	@pre	login.txt������ ��������־���Ѵ�.
	*	@post	�α��� ������ �����Ͱ� �ҷ�������.
	*	@return	�α��� ������ true, ���н� false ����
	*/
	bool login();

	/**
	*	@brief	���ã�� �߰�
	*	@pre	����
	*	@post	bookmark�� �߰���
	*/
	void bookmarkAdd();

	/**
	*	@brief	���ã�� ����
	*	@pre	����
	*	@post	bookmark�� �ϳ� ������
	*/
	void bookmarkDelete();

	/**
	*	@brief	���ã�� ���
	*	@pre	���ã�� ����� �־����
	*	@post	����
	*/
	void bookmarkPrint();

	/**
	*	@brief	���� �߶󳻱�
	*	@pre	tempPhoto�� ����� �־����
	*	@post	tempPhoto�� ������ ��
	*/
	void cutoff();

	/**
	*	@brief	������ �ٿ�����
	*	@pre	Is_tempPhoto�� true������ = ������ �߶� ���¿�����
	*	@post	Is_tempPhoto�� false�� ��
	*/
	void paste();

	/**
	*	@brief	������ ����
	*	@pre	������ ������°� �ƴϿ�����
	*	@post	������ ������°� ��
	*/
	void hidePhoto();

	/**
	*	@brief	������ ������¸� ������
	*	@pre	������ ������¿�����
	*	@post	������ ������°� Ǯ��
	*/
	void un_hidePhoto();

	/**
	*	@brief	���� ������ ���� ������ ������ �����
	*	@pre	����
	*	@post	����
	*/
	void print_hidePhoto();


private:
	ifstream m_InFile;		///< ������ �б����� �غ�
	ofstream m_OutFile;		///< ������ �������� �غ�

	int m_Command;			///< ����� �Է�
	folderType photoalbum;		///< ���� ó�� ����
	folderType *curFolder;	///< ���� �������� �ּҸ� ����
	MaxHeap<photoType*> bookmark;	// ���ã��

	Stack<folderType*> folderStack;	// ���� ���ñ���
	
	photoType tempPhoto;	// ���� ����
	bool Is_tempPhoto;		// ���� ���� á�� ��á��
};