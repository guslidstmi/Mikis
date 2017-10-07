#include "Pool.h"
#include <iostream>

Pool::Pool(unsigned long unitNum, unsigned long unitSize) :
	m_pMemPool{nullptr}
	, m_pAllocatedMemBlock{nullptr}
	, m_pFreeMemBlock{nullptr}
	, m_memPoolSize{unitNum* (unitSize+sizeof(struct memUnit))}
	, m_memUnitSize{unitSize}
{
	std::cout << "constructor called for Pool\n";

	m_pMemPool = malloc(m_memPoolSize);

	if (m_pMemPool != nullptr)
	{
		for (unsigned long i = 0; i < unitNum; ++i)
		{
			struct memUnit* pCurrentUnit = (struct memUnit*)((char*)m_pMemPool + i*(unitSize + sizeof(struct memUnit)));

			pCurrentUnit->pPrev = nullptr;
			pCurrentUnit->pNext = m_pFreeMemBlock;

			if (m_pFreeMemBlock != nullptr)
			{
				m_pFreeMemBlock->pPrev = pCurrentUnit;
			}
			m_pFreeMemBlock = pCurrentUnit;
		}
	}
}

void * Pool::Alloc(unsigned long size, bool useMemPool)
{
	if (size > m_memUnitSize || useMemPool == false || m_pMemPool == nullptr || m_pFreeMemBlock == nullptr)
	{
		return malloc(size);
	}

	struct memUnit* pCurrentUnit = m_pFreeMemBlock;
	m_pFreeMemBlock = pCurrentUnit->pNext;

	if (m_pFreeMemBlock != nullptr)
	{
		m_pFreeMemBlock->pPrev = nullptr;
	}

	pCurrentUnit->pNext = m_pAllocatedMemBlock;

	if (m_pAllocatedMemBlock != nullptr)
	{
		m_pAllocatedMemBlock->pPrev = pCurrentUnit;
	}

	m_pAllocatedMemBlock = pCurrentUnit;

	return (void*)((char*)pCurrentUnit+sizeof(struct memUnit));
}

void Pool::Free(void * p)
{
	if (m_pMemPool < p && p < (void*)((char*)m_pMemPool + m_memPoolSize))
	{
		struct memUnit* pCurrentUnit = (struct memUnit*)((char*)p - sizeof(struct memUnit));

		m_pAllocatedMemBlock = pCurrentUnit->pNext;
		if (m_pAllocatedMemBlock != nullptr)
		{
			m_pAllocatedMemBlock->pPrev = nullptr;
		}

		pCurrentUnit->pNext = m_pFreeMemBlock;
		if (m_pFreeMemBlock != nullptr)
		{
			m_pFreeMemBlock->pPrev = pCurrentUnit;
		}

		m_pFreeMemBlock = pCurrentUnit;
	}
	else
	{
		free(p);
	}
}

Pool::~Pool()
{
	std::cout << "destructor called for Pool";
	free(m_pMemPool);
}
