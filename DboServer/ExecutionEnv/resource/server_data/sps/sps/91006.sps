-- ���� ���� ����
-- ���� ���� ����
-- �߰��� �������� �ʴ� �뼱
-- ��� Path: 7


Scene(1, "7")
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
		Param( "tblidx", 7 )
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