url = './infantry.jpg';
[img_gray,img_salt_pepper] = pre(url, 0.75);

%窗口大小 5x5
n = 5;
[img_salt_pepper_resize, height, width] = resize(img_salt_pepper, n);
mean_img = self_define_mean_filter(img_salt_pepper_resize,n,height,width);
 
median_img = self_define_median_filter(img_salt_pepper_resize,n,height,width);



%联合测试
T = transform(img_gray);
T1 = transform(img_salt_pepper);
T2 = transform(mean_img);
T3 = transform(median_img);

%原图+椒盐噪音
figure;
subplot(1,2,1),imshow(img_gray),title('origin');
subplot(1,2,2),imshow(T,[]), title('originFreq');



%均值and中值处理图
figure;
subplot(3,2,1),imshow(img_salt_pepper),title('originSpeckle');
subplot(3,2,2),imshow(T1,[]), title('originSpeckleFreq');
 
subplot(3,2,3),imshow(mean_img),title('mean');
subplot(3,2,4),imshow(T2,[]), title('mean-freq');

subplot(3,2,5),imshow(median_img), title('median');
subplot(3,2,6),imshow(T3,[]), title('median-freq');



%error
error_mean = corrcoef(double(img_gray), double(mean_img));
error_median = corrcoef(double(img_gray), double(median_img));
error_salt = corrcoef(double(img_gray), double(img_salt_pepper));
error_mean = error_mean(1,2);
error_median = error_median(1,2);
error_salt = error_salt(1,2);
disp ('error_mean: ');disp(error_mean);
disp ('error_median: ');disp(error_median);
disp ('error_salt: ');disp(error_salt);















%Sobel算子卷积边缘检测
figure;

Gx = [1.0 2.0 1.0;
      0.0 0.0 0.0;
      -1.0 -2.0 -1.0];
Gy = [-1.0 0.0 1.0;
     -2.0 0.0 2.0;
     -1.0 0.0 1.0];
 
subplot(2,2,1),imshow(img_gray),title('origin-img');
gradx = conv2(Gx, img_gray,'full');
gradx = abs(gradx);
subplot(2,2,2),imshow(gradx,[]),title('gradx');
grady = conv2(Gy, img_gray,'full');
grady = abs(grady);
subplot(2,2,3),imshow(grady,[]),title('grady');

grad = gradx + grady;
subplot(2,2,4),imshow(grad,[]),title('sobel');




