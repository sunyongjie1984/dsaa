///�������ݽṹ�ඨ��
/***********************************************************************
ϵͳ����: xxxx
ģ������:
�� �� ��: skiplist.h
����˵��:
��    ��: helf
��������: 2013-7-10   10:45:52
�޸ļ�¼:
***********************************************************************/
#ifndef SKIPLIST_H
#define SKIPLIST_H

#include <stdint.h>
#include <new>
#include <iostream>

#ifdef __linux
#include <config_env.h>
#include <config_posix.h>
#endif

#define FBASE_NEW new(std::nothrow)

// #define MAX_LEVEL       32        /* Should be enough for 2^32 elements */
#define MAX_LEVEL       32

#define SKIPLIST_P      0.25

const uint32_t uint_max = 0xffffffffui32; 

class skiplistnode
{
public:
    int32_t key;
    void* val;
    skiplistnode** forward;
    int32_t level;
};

class skiplist
{
public:
    ///���캯��
    /**
     *@param bool type = true  ����ʽ��trueΪ����falseΪ����Ĭ��Ϊ����
     */
    skiplist(bool type = true);

    ///��������
    /**
     */
    ~skiplist();

    ///1.�������
    /**
     *@param const int32_t key  �ؼ���key
     *@param const void* val    �����ʹ�ã�val��ΪNULL
     *@return int32_t           ��ӳɹ�����0��ʧ�ܷ���-1
     */
    virtual int32_t add(const int32_t key, const void* val);

    ///2.ɾ������
    /**
     *@param const int32_t key  ɾ���ؼ���
     *@param void*& val = NULL  �����ⲿά�����ڴ��
     *@return int32_t           ɾ���ɹ�����0��ʧ�ܷ���-1
     */
    virtual int32_t del(const int32_t key, void*& val);

    ///3.��������
    /**
     *@param const int32_t key  ���ҹؼ���
     *@param void*& val         val�������ⲿ���أ����겻���ͷ�val�������ʹ��VAL��val��ΪNULL
     *@return int32_t           ���ڷ���0�������ڷ���-1
     */
    int32_t get(const int32_t key, void*& val);

    ///4.��������������
    /**
     *@param 
     *@return int32_t           ���������е����������շ���0
     */
    int32_t size() const;

    ///5.��������������̲߳���ȫ
    ///5.1��ʼ���������������׽ڵ�����
    /**
     *@param int32_t& key       key�������ⲿ����
     *@param void*& val         val�������ⲿ����
     *@return int32_t           �ɹ�����0������ջ��߳�����-1
     */
    int32_t first(int32_t& key, void*& val);

    ///5.2ѭ�����������������¸��ڵ�����
    /**
     *@param int32_t& key       key�������ⲿ����
     *@param void*& val         val�������ⲿ����
     *@return int32_t           �ɹ�����0���������߳�����-1
     */
    int32_t next(int32_t& key, void*& val);

    ///5.3���ñ���λ�ã�����keyֵ���õ�ǰ����ָ��
    /**
     *@param const int32_t key  key�������ⲿ����
     *@return int32_t           �ɹ�����0��������-1
     */
    int32_t locate(const int32_t key);

    ///5.4�����Ƿ����
    /**
     *@return bool              ��������true��δ��������false
     */
    bool isEof();
    void print_by_level()
    {
        skiplistnode* p;
        skiplistnode* q;
        for (int i = 0; i < m_level; i++)
        {
            p = m_header;
            std::cout << "level: " << m_level - i - 1 << std::endl;
            while ((p->level >= m_level - i - 1) && (q = p->forward[m_level - i - 1]))
            {
                std::cout << q->key << " ";
                p = q;
            }
            std::cout << std::endl;
        }
    }
protected:
    skiplistnode* createNode(const int32_t key, const void* val, int32_t level);
    int32_t randomLevel();

protected:
    bool m_type;
    int32_t m_size;
    int32_t m_level;
    skiplistnode* m_header;
    skiplistnode* m_curr;
};

class skiplist_bid : public skiplist {
public:
    skiplist_bid(bool type = true): skiplist(type), m_low(0), m_high(uint_max), m_first_valid(NULL) { }
     ///1.�������
    /**
     *@param const int32_t key  �ؼ���key
     *@param const void* val    �����ʹ�ã�val��ΪNULL
     *@return int32_t           ��ӳɹ�����0��ʧ�ܷ���-1
     */
    int32_t add(const int32_t key, const void* val);

    ///2.ɾ������
    /**
     *@param const int32_t key  ɾ���ؼ���
     *@param void*& val = NULL  �����ⲿά�����ڴ��
     *@return int32_t           ɾ���ɹ�����0��ʧ�ܷ���-1
     */
    int32_t del(const int32_t key, void*& val);
	/**
    *@param const int32_t key  ��������
    *@param const int32_t compare_key  ���ż����ڼ۸�������
     *@param void*& val         val�������ⲿ���أ����겻���ͷ�val�������ʹ��VAL��val��ΪNULL
     *@return int32_t           ���ڷ���0�������ڷ���-1
     */
    int32_t first_valid(void*& val);    
    /**
     *@param int32_t& key       key�������ⲿ����
     *@param const int32_t compare_key����Ч�۸�����ʹ�õıȽ�ֵ
     *@param void*& val         val�������ⲿ����
     *@return int32_t           �ɹ�����0���������߳�����-1
     */
    int32_t next_valid(void*& val);
    
    //
    //int32_t get_add(const int32_t key, const void* val) { return 0; }
    // �гɽ�������Ч�۸�����仯
    void set_valid_range(int32_t low, int32_t high);

    void print_valid_range()
    {
        std::cout << "valid range: [" << m_low << ", " << m_high << "]" << std::endl;
        void* val;
        int32_t ret = first_valid(val);
        if (0 == ret)
        {
            std::cout << m_curr->key << " ";
        }
        while (0 == next_valid(val))
        {
            std::cout << m_curr->key << " ";
        }
        std::cout << std::endl;
    }
private:

    void update_first_valid(bool flag);
    int32_t m_low;
    int32_t m_high;
    skiplistnode* m_first_valid;
};

#endif
