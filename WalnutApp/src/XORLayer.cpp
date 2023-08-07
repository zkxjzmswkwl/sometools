#include "XORLayer.h"

std::string ToHex(const std::string& input)
{
	std:: ostringstream ret;

	for (std::string::size_type i = 0; i < input.length(); ++i)
		ret << std::hex << std::setfill('0') << std::setw(2) << std::uppercase << (int)(unsigned char)input[i];

	return ret.str();
}

void XORLayer::OnUIRender() 
{
	ImGui::Begin("XOR");
	ImGui::Text("The last character of input should store your key.");

	ImGui::Text("Input");
	ImGui::SameLine();
	ImGui::InputText(" ", &m_Input);

	ImGui::Checkbox("Hexadecimal output", &m_HexOutput);

	if (ImGui::Button("Go"))
	{
		for (int i = 0; i < m_Input.length(); i++)
		{
			printf("%c", m_Input[i]);
			m_Input[i] ^= m_Input.at(m_Input.length() - 1);
		}

		if (m_HexOutput)
			m_Input = ToHex(m_Input);
	}
	ImGui::End();
}

