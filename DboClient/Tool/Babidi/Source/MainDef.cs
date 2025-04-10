namespace Babidi
{
    /// <summary>
    /// Babidi_Log�� ��µ� Ÿ��
    /// </summary>
    enum eLogType
    {
        eLOGTYPE_FILE = 0,          // FILE ó������ ����
        eLOGTYPE_ID,                // ID   ���� ����
        eLOGTYPE_LINE_OVER,         // LINE OVER�� ����
        eLOGTYPE_LENGTH_OVER,       // LENGTH OVER�� ����
        eLOGTYPE_CONFIG,            // CONFIG ������ ����
        eLOGTYPE_EDIT,              // ���� �󿡼��� ����

        eLOGTYPE_NUMS,
        eLOGTYPE_INVALID = 0xFF
    }
}