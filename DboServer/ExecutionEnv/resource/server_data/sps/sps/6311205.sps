Scene( 1, "6311205" )
--[
	Action( "char condition" )
	--[
		Param( "invincible", 0 )
		Param( "ui disable", 1 )
	--]
	End()

	-- ȣȣȣ! �, �����? �� ��¥ �����̾�~
	Action( "say" )
	--[
		Param( "tblidx", 3271 )
	--]
	End()
	
	-- ����� ���� ���� �̺�Ʈ�� ��ٸ�
	-- �Ʒ��� �̺�Ʈ 466�� sps 7112225���� ���� �ʴ� �̺�Ʈ�� ��ٸ��� �ϱ� ����
	-- ó�� ��������� �ݺ��ؼ� ����ص� ������ٰ� ����
	Action( "wait" )
	--[
		Condition( "recv event from wps" )
		--[
			Param( "wps index", 2628 )
			Param( "event id", 466 )
		--]
		End()
	--]
	End()

	Action( "sps end" )
	--[
	--]
	End()
--]
End()
