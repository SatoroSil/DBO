-- ���� ���� ����
-- ���� ���� ����
-- �߰��� �������� �ʴ� �뼱
-- ��� Path: 6


Scene(1, "6")
--[
	Action("sitdown")
	--[
		Param( "sitdown", "true" )
	--]
	End()

	Action("wait")
	--[
		Param( "time", 3 )
	--]
	End()

	Action("say")
	--[
		Param( "tblidx", 2000 )
		-- �̵��� ���Ͻø� �����ϼ���
	--]
	End()

	Action("wait")
	--[
		Param( "time", 9 )
	--]
	End()

	Action("say")
	--[
		Param( "tblidx", 2036 )
		---- ���� ���� ���� ���� ����ϰڽ��ϴ�
	--]
	End()

	Action("sitdown")
	--[
		Param( "sitdown", "false" )
	--]
	End()

	Action("wait")
	--[
		Param( "time", 3)
	--]
	End()

	Action("path move")
	--[
		Param( "tblidx", 6 )
		Param( "run mode", 0 )
		---- ��� Path�� �� �ϳ�����
	--]
	End()

	Action("say")
	--[
		Param( "tblidx", 2001 )
		-- �����忡 �����߽��ϴ�
	--]
	End()

	Action("wait")
	--[
		Param( "time", 3 )
	--]
	End()

	Action("sitdown")
	--[
		Param( "sitdown", "true" )
	--]
	End()

	Action("wait")
	--[
		Param( "time", 5 )
	--]
	End()

	Action( "leave" )
	--[
	--]
	End()

	Action( "sps end" )
	--[
	--]
	End()
--]
End()