#include "stdafx.h"

using namespace std;

namespace Error {

	// Legacy
	static ErrorBase ErrorsPool[MAX_ERRORS_COUNT]{
		ERROR_THROW(0, "������������ ��� ������"),
		ERROR_THROW(1, "��������� ����"),

		ERROR_THROW_NODEF(2), ERROR_THROW_NODEF(3), ERROR_THROW_NODEF(4), ERROR_THROW_NODEF(5),
		ERROR_THROW_NODEF(6), ERROR_THROW_NODEF(7), ERROR_THROW_NODEF(8), ERROR_THROW_NODEF(9),

		ERROR_THROW_NODEF10(10), ERROR_THROW_NODEF10(20), ERROR_THROW_NODEF10(30), ERROR_THROW_NODEF10(40), ERROR_THROW_NODEF10(50),
		ERROR_THROW_NODEF10(60), ERROR_THROW_NODEF10(70), ERROR_THROW_NODEF10(80), ERROR_THROW_NODEF10(90),

		ERROR_THROW(100, "�������� -IN ������ ���� �����!"),

		ERROR_THROW_NODEF(101), ERROR_THROW_NODEF(102), ERROR_THROW_NODEF(103),

		ERROR_THROW(104, "��������� ������ �������� ���������!"),

		ERROR_THROW_NODEF(105), ERROR_THROW_NODEF(106), ERROR_THROW_NODEF(107), ERROR_THROW_NODEF(108), ERROR_THROW_NODEF(109),

		ERROR_THROW(110, "������ ��� �������� ����� [-IN]"),
		ERROR_THROW(111, "������������ ������ � �������� ����� [-IN]"),
		ERROR_THROW(112, "������ ��� �������� ����� ��������� [-log]"),
		ERROR_THROW(113, "������ ��� �������� ����� ���������� ���������� [-out]"),

		ERROR_THROW_NODEF(114), ERROR_THROW_NODEF(115),
		ERROR_THROW_NODEF(116), ERROR_THROW_NODEF(117), ERROR_THROW_NODEF(118), ERROR_THROW_NODEF(119),

		ERROR_THROW_NODEF10(120), ERROR_THROW_NODEF10(130), ERROR_THROW_NODEF10(140), ERROR_THROW_NODEF10(150),
		ERROR_THROW_NODEF10(160), ERROR_THROW_NODEF10(170), ERROR_THROW_NODEF10(180), ERROR_THROW_NODEF10(190),

		ERROR_THROW_NODEF100(200), ERROR_THROW_NODEF100(300), ERROR_THROW_NODEF100(400), ERROR_THROW_NODEF100(500),
		ERROR_THROW_NODEF100(600), ERROR_THROW_NODEF100(700), ERROR_THROW_NODEF100(800), ERROR_THROW_NODEF100(900)
	};

	string ErrorBase::ToString()
	{
		strstream result;

		result << "ID: " << id << endl << "MESSAGE: " << message << '\0';

		return result.str();
	}

	string LineError::ToString()
	{
		string base = ErrorBase::ToString();

		strstream result;

		result << endl << "Line index: " << lineIndex << ", Letter index: " << letterIndex << '\0';

		return base + result.str();
	}

	ErrorBase GetError(int id)
	{
		if (id < 0 || id > MAX_ERRORS_COUNT - 1) throw ErrorsPool[0];

		return ErrorsPool[id];
	}
	LineError GetError(int id, int line, int letter)
	{
		if (id < 0 || id > MAX_ERRORS_COUNT - 1) throw ErrorsPool[0];

		return LineError(id, ErrorsPool[id].message, line, letter);
	}
}