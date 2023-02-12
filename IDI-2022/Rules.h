#pragma once
#include "GRB.h"
//TS - �������, NS - �������. ����� ���� ������������ ������. ��� ������������ ������ ���������� ������������ ������������� ������ � ����� ��������. ������� ����� �������� ������ �������
namespace GRB
{
	Greibach greibach(NS('S'), TS('$'), 19,

		Rule(NS('S'), GRB_ERROR_SERIES, 4,						// �������� ��������� ���������	
			Rule::Chain(6, TS('t'), TS('f'), TS('i'), NS('P'), NS('T'), NS('S')),
			Rule::Chain(6, TS('g'), TS('f'), TS('i'), NS('P'), NS('G'), NS('S')),
			Rule::Chain(4, TS('m'), TS('{'), NS('K'), TS('}')),
			Rule::Chain(3, TS('m'), TS('{'), TS('}'))
		),

		Rule(NS('T'), GRB_ERROR_SERIES + 2, 2,								// ������ � ���� �������
			Rule::Chain(3, TS('{'), NS('Q'), TS('}')),
			Rule::Chain(4, TS('{'), NS('K'), NS('Q'), TS('}'))
		),

		Rule(NS('P'), GRB_ERROR_SERIES + 1, 2,								// �� ������ ������ ���������� �������	
			Rule::Chain(3, TS('('), NS('E'), TS(')')),
			Rule::Chain(2, TS('('), TS(')'))
		),

		Rule(NS('E'), GRB_ERROR_SERIES + 3, 2,								// ������ � ������ ���������� �������						
			Rule::Chain(4, TS('t'), TS('i'), TS(','), NS('E')),
			Rule::Chain(2, TS('t'), TS('i'))
		),

		Rule(NS('F'), GRB_ERROR_SERIES + 4, 2,								// ������ � ������ �������						
			Rule::Chain(3, TS('('), NS('N'), TS(')')),
			Rule::Chain(2, TS('('), TS(')'))
		),

		Rule(NS('N'), GRB_ERROR_SERIES + 5, 4,								// ������ � ������ ���������� �������		
			Rule::Chain(1, TS('i')),
			Rule::Chain(1, TS('l')),
			Rule::Chain(3, TS('i'), TS(','), NS('N')),
			Rule::Chain(3, TS('l'), TS(','), NS('N'))
		),

		Rule(NS('R'), GRB_ERROR_SERIES + 6, 4,								// ������ ��� �������������� ��������� ���������	
			Rule::Chain(2, TS('y'), NS('Y')),
			Rule::Chain(2, TS('n'), NS('Y')),
			Rule::Chain(4, TS('y'), NS('Y'), TS('n'), NS('Y')),
			Rule::Chain(4, TS('w'), NS('Y'), TS('y'), NS('Y'))
		),
		Rule(NS('Z'), GRB_ERROR_SERIES + 8, 5,								// ������ � ������� �����/��������� ���������	
			Rule::Chain(3, TS('i'), NS('L'), TS('i')),
			Rule::Chain(3, TS('i'), NS('L'), TS('l')),
			Rule::Chain(3, TS('l'), NS('L'), TS('l')),
			Rule::Chain(3, TS('l'), NS('L'), TS('i')),
			Rule::Chain(1, TS('i'))
		),

		Rule(NS('L'), GRB_ERROR_SERIES + 9, 6,				// �������� �������� ��������		/ ���������� ���������
			Rule::Chain(1, TS('0')), // ==
			Rule::Chain(1, TS('1')), // !=
			Rule::Chain(1, TS('2')), // >=
			Rule::Chain(1, TS('3')),  // <=
			Rule::Chain(1, TS('>')), // >
			Rule::Chain(1, TS('<')) // <
		),

		Rule(NS('A'), GRB_ERROR_SERIES + 10, 5,											// �������� �������������� ��������
			Rule::Chain(1, TS('+')),
			Rule::Chain(1, TS('-')),
			Rule::Chain(1, TS('*')),
			Rule::Chain(1, TS('%')),
			Rule::Chain(1, TS('/'))
		),
		Rule(NS('W'), GRB_ERROR_SERIES + 11, 12,										// ������ � ������������� ���������
			Rule::Chain(1, TS('i')),
			Rule::Chain(1, TS('l')),
			Rule::Chain(3, TS('('), NS('W'), TS(')')),
			Rule::Chain(4, TS('('), TS('-'), TS('i'), TS(')')),
			Rule::Chain(6, TS('('), TS('-'), TS('i'), TS(')'), NS('A'), NS('W')),
			Rule::Chain(5, TS('('), NS('W'), TS(')'), NS('A'), NS('W')),
			Rule::Chain(2, TS('i'), NS('F')),
			Rule::Chain(2, TS('p'), NS('F')),
			Rule::Chain(3, TS('i'), NS('A'), NS('W')),
			Rule::Chain(3, TS('l'), NS('A'), NS('W')),
			Rule::Chain(4, TS('i'), NS('F'), NS('A'), NS('W')),
			Rule::Chain(4, TS('p'), NS('F'), NS('A'), NS('W'))
		),

		Rule(NS('K'), GRB_ERROR_SERIES + 12, 20,							// ������������ �������������� �����������
			Rule::Chain(6, TS('?'), TS('('), NS('Z'), TS(')'), NS('R'), NS('K')),				// if
			Rule::Chain(7, TS('c'), TS('('), NS('Z'), TS(')'), TS('d'), NS('H'), NS('K')),	// while
			Rule::Chain(5, TS('?'), TS('('), NS('Z'), TS(')'), NS('R')),						// if
			Rule::Chain(6, TS('c'), TS('('), NS('Z'), TS(')'), TS('d'), NS('H')),				// while	

			Rule::Chain(7, TS('v'), TS('t'), TS('i'), TS('='), NS('V'), TS(';'), NS('K')),	// ���������� + ������������
			Rule::Chain(7, TS('v'), TS('t'), TS('i'), TS('='), NS('W'), TS(';'), NS('K')),	// ���������� + ������������
			Rule::Chain(5, TS('v'), TS('t'), TS('i'), TS(';'), NS('K')),	// ����������
			Rule::Chain(5, TS('i'), TS('='), NS('W'), TS(';'), NS('K')),	// ������������


			Rule::Chain(4, TS('o'), NS('V'), TS(';'), NS('K')),				// �����
			Rule::Chain(4, TS('^'), NS('V'), TS(';'), NS('K')),						// ������� ������
			Rule::Chain(6, TS('i'), TS('='), TS('U'), NS('F'), TS(';'), NS('K')),	// ������������ c ������� ������ ������� 

			Rule::Chain(4, TS('i'), NS('F'), TS(';'), NS('K')),				// ����� �������

			Rule::Chain(6, TS('v'), TS('t'), TS('i'), TS('='), NS('V'), TS(';')),	// ���������� + ������������
			Rule::Chain(6, TS('v'), TS('t'), TS('i'), TS('='), NS('W'), TS(';')),	// ���������� + ������������
			Rule::Chain(4, TS('i'), TS('='), NS('W'), TS(';')),				// ������������
			Rule::Chain(4, TS('v'), TS('t'), TS('i'), TS(';')),				// ����������
			Rule::Chain(3, TS('o'), NS('V'), TS(';')),						// �����
			Rule::Chain(3, TS('^'), NS('V'), TS(';')),								// ������� ������

			Rule::Chain(5, TS('i'), TS('='), TS('U'), NS('F'), TS(';')),	// ������������ c ������� ������ �������
			Rule::Chain(3, TS('i'), NS('F'), TS(';'))			// ����� �������
		),

		Rule(NS('X'), GRB_ERROR_SERIES + 13, 14,								// ������������ �������������� ����������� � ���� �����/��������� ���������	

			Rule::Chain(6, TS('?'), TS('('), NS('Z'), TS(')'), NS('R'), NS('X')),				// if
			Rule::Chain(7, TS('c'), TS('('), NS('Z'), TS(')'), TS('d'), NS('H'), NS('X')),	// while
			Rule::Chain(5, TS('?'), TS('('), NS('Z'), TS(')'), NS('R')),						// if
			Rule::Chain(6, TS('c'), TS('('), NS('Z'), TS(')'), TS('d'), NS('H')),				// while	

			Rule::Chain(5, TS('i'), TS('='), NS('W'), TS(';'), NS('X')),		// ������������
			Rule::Chain(4, TS('o'), NS('V'), TS(';'), NS('X')),					// �����
			Rule::Chain(4, TS('^'), NS('V'), TS(';'), NS('X')),						// ������� ������
			Rule::Chain(6, TS('i'), TS('='), TS('U'), NS('F'), TS(';'), NS('K')),	// ������������ c ������� ������ ������� 

			Rule::Chain(4, TS('i'), NS('F'), TS(';'), NS('K')),						// ����� �������

			Rule::Chain(4, TS('i'), TS('='), NS('W'), TS(';')),						// ������������
			Rule::Chain(3, TS('o'), NS('V'), TS(';')),								// �����
			Rule::Chain(3, TS('^'), NS('V'), TS(';')),								// ������� ������
			Rule::Chain(5, TS('i'), TS('='), TS('U'), NS('F'), TS(';')),			// ������������ c ������� ������ ������� 

			Rule::Chain(3, TS('i'), NS('F'), TS(';'))								// ����� �������
		),
		Rule(NS('Q'), GRB_ERROR_SERIES + 7, 4,						// ������ ��� ��������������� return
			Rule::Chain(3, TS('e'), NS('V'), TS(';')),
			Rule::Chain(6, TS('e'), TS('('), TS('-'), TS('i'), TS(')'), TS(';')),
			Rule::Chain(2, TS('e'), TS(';')),
			Rule::Chain(5, TS('e'), TS('('), TS('l'), TS(')'), TS(';'))
		),
		Rule(NS('Y'), GRB_ERROR_SERIES + 16, 4,						// ������ � ���� ��������� ���������
			Rule::Chain(4, TS('['), NS('X'), NS('Q'), TS(']')),
			Rule::Chain(3, TS('['), NS('X'), TS(']')),
			Rule::Chain(3, TS('['), NS('Q'), TS(']')),
			Rule::Chain(2, TS('['), TS(']'))
		),
		Rule(NS('H'), GRB_ERROR_SERIES + 17, 4,						// ������ � ���� �����	
			Rule::Chain(4, TS('['), NS('X'), NS('Q'), TS(']')),
			Rule::Chain(3, TS('['), NS('Q'), TS(']')),
			Rule::Chain(3, TS('['), NS('X'), TS(']')),
			Rule::Chain(2, TS('['), TS(']'))
		),
		Rule(NS('V'), GRB_ERROR_SERIES + 15, 2,						// ������� ��� ��������������� ��� ���������	
			Rule::Chain(1, TS('i')),
			Rule::Chain(1, TS('l'))
		),

		Rule(NS('U'), GRB_ERROR_SERIES + 3, 2,						// ������� ��� �������������� �������	
			Rule::Chain(1, TS('i')),
			Rule::Chain(1, TS('p'))
		),
		Rule(NS('G'), GRB_ERROR_SERIES + 2, 2,						// ������ � ���� ���������
			Rule::Chain(4, TS('{'), TS('e'), TS(';'), TS('}')),
			Rule::Chain(5, TS('{'), NS('K'), TS('e'), TS(';'), TS('}'))
		)
	);
}