#pragma once

class Pool
{
public:

	Pool(unsigned long unitNum = 50, unsigned long unitSize = 1024);
	void* Alloc(unsigned long size, bool useMemPool);
	void Free(void* p);
	~Pool();

private:
	struct memUnit
	{
		struct memUnit* pPrev;
		struct memUnit* pNext;
	};

	void *m_pMemPool;

	struct memUnit* m_pAllocatedMemBlock;
	struct memUnit* m_pFreeMemBlock;

	unsigned long m_memUnitSize;
	unsigned long m_memPoolSize;
	
};