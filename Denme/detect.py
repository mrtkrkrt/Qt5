import cv2
import numpy as np
import matplotlib.pyplot as plt

img = cv2.imread("1_org.jpg")
img = cv2.resize(img, (750, 750))
blurred = cv2.GaussianBlur(img, (11,11), 0)
hsv_img = cv2.cvtColor(blurred, cv2.COLOR_BGR2HSV)
plt.imshow(hsv_img)
plt.show()
plt.figure()

# https://www.rapidtables.com/web/color/RGB_Color.html
redLower = (20, 150, 150)
redUpper = (190, 255, 255)

mask = cv2.inRange(hsv_img, redLower, redUpper)
plt.imshow(mask)
plt.show()
plt.figure()
# maskenin etrafında kalan gürültüleri sil
mask = cv2.erode(mask, None, iterations = 2)
mask = cv2.dilate(mask, None, iterations = 2)
plt.imshow(mask)
plt.show()
plt.figure()

# Gürültüleri direk img üzerinde uyguladığımız görüntüden silersek aldığımız çember sınırlarının kaybolduğunu gördük

# kontür işleme 
(contours, _) =  cv2.findContours(mask.copy(), cv2.RETR_EXTERNAL, cv2.CHAIN_APPROX_SIMPLE)

if len(contours) > 0:

    # en güçlüsünü al
    c = max(contours, key = cv2.contourArea)

    rect = cv2.minAreaRect(c)
            
    ((x,y), (width,height), rotation) = rect
    
    s = "x: {}, y: {}, width: {}, height: {}, rotation: {}".format(np.round(x),np.round(y),np.round(width),np.round(height),np.round(rotation))
    print(s)
    
    # kutucuk
    box = cv2.boxPoints(rect)
    box = np.int64(box)
    
    # moment
    M = cv2.moments(c)
    center = (int(M["m10"]/M["m00"]), int(M["m01"]/M["m00"]))
    
    # konturu çizdir: sarı
    cv2.drawContours(img, [box], 0, (0,255,255),2)
    
    # merkere bir tane nokta çizelim: pembe
    cv2.circle(img, center, 5, (255,0,255),-1)

    # bilgileri ekrana yazdır
    cv2.putText(img, s, (25,50), cv2.FONT_HERSHEY_COMPLEX_SMALL, 1, (255,0,255), 2)

    while True:
        cv2.imshow("Final Result", img)
    
        if cv2.waitKey(1) & 0xFF == ord("q"): break