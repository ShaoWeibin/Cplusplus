#ifndef _BUILDER_PRODUCT_H_
#define _BUILDER_PRODUCT_H_

class BuilderProduct
{
public:
	BuilderProduct();
	~BuilderProduct();

	void ProducePart();
};

class ProductPart
{
public:
	ProductPart();
	~ProductPart();

	ProductPart* BuildPart();
};

#endif  // _BUILDER_PRODUCT_H_