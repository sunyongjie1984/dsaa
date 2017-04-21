///��̬��ϣ���ݽṹ����
/***********************************************************************
ϵͳ����: NEEQ1.0
ģ������:
�� �� ��: static_hash.h
����˵��:
��    ��: �����
��������: 2013-7-10   10:47:29
�޸ļ�¼:
***********************************************************************/
#ifndef STATIC_HASH_H
#define STATIC_HASH_H

#include "os/config_env.h"


#define DICT_OK                 0
#define DICT_ERR                -1
#define HT_BASE_SIZE            2
#define HASH_FUNCTION_SEED      5381

class CHash
{
public:
    ///���캯��
    /**
     *@param uint32_t keyLen: key�ĳ��ȣ�����
     *@param uint32_t size: ��̬��ϣ������ݹ�ģ
     */
    CHash(uint32_t keyLen, uint32_t size);

    ///��������
    /**
     */
    virtual ~CHash();

    ///1.���ӽӿ�
    /**
     *@param const char* key: keyֵ������Ϊ�գ��ڲ��´�����ַ���
     *@param const void* val: valֵ������Ϊ�գ��ڲ�����������
     *@return int32_t: ���ز��������0��ʾ�ɹ���-1��ʾʧ��
     */
    int32_t add(const char* key, const void* val);

    ///2.ɾ���ӿ�
    /**
     *@param const void* key: keyֵ������Ϊ��
     *@param void*& val: valֵ������val�ľ��
     *@return int32_t: ���ز��������0��ʾ�ɹ���-1��ʾʧ��
     */
    int32_t del(const char* key, void*& val);

    ///3.���ҽӿ�
    /**
     *@param const char* key: keyֵ������Ϊ��
     *@param void*& val: valֵ������val�ľ��
     *@return int32_t: ���ز��ҽ����0��ʾ�ɹ���-1��ʾʧ��
     */
    int32_t get(const char* key, void*& val);

    ///4.�����������ӿ�
    /**
     *@return uint32_t: ���ر���������
     */
    uint32_t size() const;

private:
    /* define: bucket */
    struct dictEntry
    {
        void* key;
        void* val;
        struct dictEntry* next;
    };

    /* define: table */
    struct dictht
    {
        dictEntry** table;
        uint32_t size;
        uint32_t mask;
        uint32_t used;
    };

private:
    /* ȡ�պô���uiSize��2^n */
    uint32_t nextPower(uint32_t size);

    /* hash���㺯�� */
    uint32_t hashFunction(const unsigned char* key, uint32_t len);

    /* �ַ����Ƚ� */
    bool keyCompare(const void* key1, const void* key2);

    /* �ͷ���Դ */
    int32_t freeEntry(dictEntry* de);

private:
    uint32_t m_keylen;  /* key�ĳ��� */
    dictht dt;          /* �ʵ� */
};

#endif
