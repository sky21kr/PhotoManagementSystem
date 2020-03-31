#include"SortedList.h"

/**
*	����Ÿ�� Ŭ����
*/
class photoType
{
public:
	
	// �⺻ ������
	photoType()
	{
		photoName = "";
		date = "";
		size = 0;
	}
	/**
	*	@brief	������ ������ �����
	*	@pre	������ ������ �����Ǿ��� �־����
	*	@post	����
	*/
	void DisplayPhoto();

	/**
	*	@brief	������ �̸��� �޾ƿ�
	*	@pre	������ �̸��� �����Ǿ��� �־����
	*	@post	����
	*	@param	������ �̸�
	*/
	string GetName();

	/**
	*	@brief	������ ��¥�� �޾ƿ�
	*	@pre	������ ��¥�� �����Ǿ��� �־����
	*	@post	����
	*	@return	������ ��¥�� ������
	*/
	string getdate();

	/**
	*	@brief	������ ����� �޾ƿ�
	*	@pre	������ ����� �����Ǿ��� �־����
	*	@post	����
	*	@return	������ ����� ������
	*/
	int getsize();

	/**
	*	@brief	���� ���¸� ��ȯ��
	*	@pre	����
	*	@post	����
	*	@return ������¸� true �ƴϸ� false ��ȯ
	*/
	bool gethide();

	/**
	*	@brief  ���ã�� ���¸� ��ȯ��
	*	@pre	����
	*	@post	����
	*	@return	���ã����¸� true, �ƴϸ� false ��ȯ 
	*/
	int getbook();

	/**
	*	@brief	������ ������ �޾ƿ�
	*	@pre	������ ������ �����Ǿ��� �־����
	*	@post	����
	*	@return	������ ������ ������
	*/
	string getcontent();

	/**
	*	@brief	������ �̸��� Ű����� ���� �޾� ������
	*	@pre	����
	*	@post	������ �̸��� ������
	*/
	void setphotoNameKB();

	/**
	*	@brief	������ ������¥�� Ű����κ��� �޾� ������
	*	@pre	����
	*	@post	������ ������¥�� ������
	*/
	void setdateKB();

	/**
	*	@brief	������ ����� Ű����κ��� �޾� ������
	*	@pre	����
	*	@post	������ ����� ������
	*/
	void setsizeKB();

	/**
	*	@brief	������ ������ Ű����κ��� �޾� ������
	*	@pre	����
	*	@post	������ ������ ������
	*/
	void setcontentKB();

	/**
	*	@brief	������ �̸��� ������
	*	@pre	����
	*	@post	������ �̸��� ������
	*	@param	temp_name	������ �̸�
	*/
	void setname(string temp_name);

	/**
	*	@brief	������ ��¥�� ������
	*	@pre	����
	*	@post	������ ��¥�� ������
	*	@param	temp_date	������ ��¥
	*/
	void setdate(string temp_date);
	
	/**
	*	@brief	������ ����� ������
	*	@pre	����
	*	@post	������ ����� ������
	*	@param	temp_size	������ ������
	*/
	void setsize(int temp_size);

	/**
	*	@brief	������ ������ ������
	*	@pre	����
	*	@post	������ ������ ������
	*	@param	temp_content	������ ����
	*/
	void setconstent(string temp_content);

	/**
	*	@brief	���� ���¸� ������
	*	@pre	����
	*	@post	���� ���°� ������
	*	@param	temp_hide ���� ����
	*/
	void sethide(bool temp_hide);

	/**
	*	@brief	���ã�� ���¸� ������
	*	@pre	����
	*	@post	���ã�� ���°� ������
	*	@param	temp_book ���ã�� ����
	*/
	void setbook(int temp_book);

	/**
	*	@brief	������ ������ ����
	*	@pre	��������Ʈ�� �ʱ�ȭ �Ǿ��� �־����
	*	@post	����
	*	@param	data	�̸��� ������ ������
	*	@return ���� ������ �̸������� ������ GREATER ������ EQUAL ������ LESS�� ��ȯ��
	*/
	RelationType CompareByName(const photoType &data);

	// ������ �����ε� �̸����� ��
	bool operator>(photoType item);
	
	// ������ �����ε� �̸����� ��
	bool operator<(photoType item);
private:
	string photoName;	///< �����̸�
	string date;		///< ����������¥
	int size;			///< ����ũ��
	string content;		///< ��������
	bool hide;			///< �������
	int book;			///< ���ã�� ����
};