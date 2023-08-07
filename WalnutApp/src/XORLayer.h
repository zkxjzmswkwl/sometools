#pragma once
#include "Walnut/Application.h"
#include "Walnut/Image.h"
#include "Walnut/UI/UI.h"

#include <string>

std::string ToHex(const std::string&);

class XORLayer : public Walnut::Layer
{
public:
	virtual void OnUIRender() override;

private:
	bool m_AboutModalOpen = false;
	bool m_HexOutput = false;
	std::string m_Input;
	std::string m_XorBy;
};
