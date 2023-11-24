#pragma once
#include <memory>
#include "Structures.h"

//Handles any properties surrounding the 'appearance' of an object
class Appearance
{
public:
	Appearance(std::shared_ptr<Geometry> geometry, std::shared_ptr <Material> material);
	~Appearance();
	void Draw(ID3D11DeviceContext* pImmediateContext);

	std::shared_ptr<Geometry> GetGeometryData() const { return _geometry; }

	std::shared_ptr <Material> GetMaterial() const { return _material; }

	void SetTextureRV(ID3D11ShaderResourceView* textureRV) { _textureRV = textureRV; }
	ID3D11ShaderResourceView* GetTextureRV() const { return _textureRV; }
	bool HasTexture() const { return _textureRV ? true : false; }

private:
	std::shared_ptr<Geometry> _geometry;
	std::shared_ptr <Material> _material;


	ID3D11ShaderResourceView* _textureRV;
};

