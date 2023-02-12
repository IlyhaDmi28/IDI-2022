#include "stdafx.h"
#include <mbstring.h>
#include <iostream>

namespace FST
{
	RELATION::RELATION(unsigned char c, short nn)
	{
		symbol = c;
		nnode = nn;
	};

	NODE::NODE()
	{
		n_relation = 0;
		relations = nullptr;
	};

	NODE::NODE(short n, RELATION rel, ...)
	{
		n_relation = n;
		RELATION* p = &rel;
		relations = new RELATION[n];

		for (size_t i = 0; i < n; i++)
		{
			relations[i] = p[i];
		}
	};

	FST::FST(short ns, NODE n, ...)
	{
		nodes = new NODE[ns];
		NODE* temp = &n;
		nstates = ns;
		rstates = new short[ns];
		for (short i = 0; i < ns; i++)
			nodes[i] = *(temp + i);
		rstates[0] = 0;
		position = -1;
	}

	FST::FST(unsigned char* s, FST& fst)
	{
		nodes = new NODE[fst.nstates];
		NODE* temp = fst.nodes;
		string = s;
		nstates = fst.nstates;
		rstates = new short[nstates];
		for (short i = 0; i < nstates; i++)
			nodes[i] = *(temp + i);
		rstates[0] = 0;
		position = -1;
	}
	bool step(FST& fst, short*& rstates)
	{
		bool rc = false;
		std::swap(rstates, fst.rstates);
		for (short i = 0; i < fst.nstates; i++)
		{
			if (rstates[i] == fst.position) //≈сли позици€ строки не равна номеру сотстани€, в который надо перейти, то мы ничего не делаем. ∆дЄм пока, не дайдЄм до элемента, значение которого будет соответствовать номеру сотстани€, в который надо перейти. ≈сли мы такого не находим, это значит что нет такого ссото€ни€, которое расматривает сиволы, схожие на текущий символ строки, что озночает разбор был завершЄн не верно и rc так и не станет true и вернЄтс€ false, и прграмма поймЄт, что такой токен недоступен
				for (short j = 0; j < fst.nodes[i].n_relation; j++)
				{
					if (fst.nodes[i].relations[j].symbol == fst.string[fst.position]) //—вер€ем каждый символ состо€ни€ с символом строки, если есть равные, то мы ..
					{
						fst.rstates[fst.nodes[i].relations[j].nnode] = fst.position + 1;  //¬ элемент массива, в котором индексы элементов соответствуют соста€ни€м, в которых хранитс€ номер другого состо€ни€ состо€ни€, в которое надо перейти. » мы в элемент массива помещаем позицию расматриваемой строки. 
						rc = true;
					};
				};
		};
		return rc;
	};
	bool execute(FST& fst)
	{
		short* rstates = new short[fst.nstates];
		memset(rstates, 0xff, sizeof(short) * fst.nstates); // memset заполнить массив rstates первые 2 * кол. сото€ний автомата байт числом 255
		short lstring = _mbslen(fst.string); // _mbslen возвращают количество многобайтовых символов в многобайтовой строке
		bool rc = true;
		for (short i = 0; i < lstring && rc; i++)
		{
			fst.position++;
			rc = step(fst, rstates); //провер€ет соответстви€ символов состо€ни€ c символами слова
		};
		delete[] rstates;
		return (rc ? (fst.rstates[fst.nstates - 1] == lstring) : rc); //провер€ет соответстви€ символов состо€ни€ c символами слова
		/*если всЄ нормально, step всЄ же венула true, то это не факт что были просмотрены все состо€ни€ автомата.Ќа это иделаетс€ последн€€ првека, хранитс€ ли в
		в последнем элементе rstates количество элементов слова(в rstates должны хранитс€ номера переходов, и елси пройден был всЄ слово, то последним номером
		последнего перехода должено быть число, соответствующее числу символов в токене).≈сли не совпадает, это значит что гдето в состо€ни€х символы не были равны
		значит цепочка не была раобрана и excute возвращет false*/
	};


}