-- ��Ÿ ���� �پ� ������ ����

Scene(1, "8391201")
--[
	-- ��Ÿ ���� '�� �༮�� ������� �� ���̾�...'
	Action( "say" )
	--[
		Param( "tblidx", 3234 )
	--]
	End()

	-- 2�ʰ� ��ٸ��� ��縦 ������
	Action( "wait" )
	--[
		Param( "time", 2 )
	--]
	End()

	-- �ٸ� �Ʒ��� �پ� ������ ����
	Action( "direct play" )
	--[
		Param( "tblidx", 60056 )
	--]
	End()

	-- ���� ���� ����� wps�� ����
	Action( "send event to wps" )
	--[
		Param( "wps index", 32006 )
		Param( "event id", 487 )
	--]
	End()

	Action( "sps end" )
	--[
	--]
	End()
--]
End()