function [img_gray,img_salt_pepper] = pre(url, salt_rate)
%ͼ��Ԥ����תΪ�Ҷ�ͼ
img = imread(url);
img_gray = rgb2gray(img);

%�������

img_salt_pepper=imnoise(img_gray,'speckle');

%img_salt_pepper=imnoise(img_gray,'gaussian');

%img_salt_pepper=imnoise(img_gray,'salt & pepper');
%img_salt_pepper=imnoise(img_gray,'salt & pepper',salt_rate);
end