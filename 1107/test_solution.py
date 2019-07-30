from solution import sol


def test_1():
    assert sol('5457', '3', '6 7 8') == 6


def test_2():
    assert sol('100', '5', '0 1 2 3 4') == 0


def test_3():
    assert sol('500000', '8', '0 2 3 4 6 7 8 9') == 11117


def test_4():
    assert sol('10', '9', '1 2 3 4 5 6 7 8 9') == 11


def test_5():
    assert sol('101', '0', '') == 1


def test_6():
    assert sol('99', '10', '0 1 2 3 4 5 6 7 8 9') == 1


def test_7():
    assert sol('0', '0', '') == 1


def test_8():
    assert sol('500000', '6', '0 1 2 3 4 5') == 166672


def test_9():
	assert sol('0', '2', '0 1') == 3


def test_10():
	assert sol('1555', '8', '0 1 3 4 5 6 7 9') == 670


def test_11():
	assert sol('944', '7', '2 3 4 5 6 7 9') == 59


def test_12():
	assert sol('6', '9', '0 2 3 4 5 6 7 8 9') == 6


def test_13():
	assert sol('500000', '10', '0 1 2 3 4 5 6 7 8 9') == 499900


def test_14():
	assert sol('101', '10', '0 1 2 3 4 5 6 7 8 9') == 1


def test_15():
	assert sol('1', '9', '1 2 3 4 5 6 7 8 9') == 2


def test_16():
	assert sol('99999', '1', '9') == 7


def test_17():
	assert sol('10', '1', '0') == 2


def test_18():
	assert sol('0', '3', '0 1 2') == 4


def test_19():
	assert sol('0', '9', '0 1 2 3 4 5 6 7 8') == 10


def test_20():
    assert sol('0', '10', '0 1 2 3 4 5 6 7 8 9') == 100